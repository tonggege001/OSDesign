#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cpuinfomodel.h"
#include <QDir>
#include <QFrame>
#include <QStandardItemModel>
#include <QTimer>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //test
    /*ProcessInfoModel a;
    a.Pid = "2564";
    a.TidList.append("2565");
    a.CPUUsage = 0.5;
    a.MemUsage = 0.2;
    a.NetUsage = 0.7;
    a.DiskReadSpeed = 1.2;
    this->ProcessInfo.append(a);
*/

    MakeMainWindowLayout();
    Fresh();
    QTimer * qtimer = new QTimer (this);
    connect(qtimer,SIGNAL(timeout()),this,SLOT(Fresh()));
    qtimer->start(1000);
    NetInfo.TimeScale = qtimer->interval();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MakeMainWindowLayout(){
    //set background
    QPalette pal(this->palette());
    pal.setColor(QPalette::Background,QColor(0x9f,0xc5,0xe8,255)); //设置背景黑色
    this->setPalette(pal);
    ui->CPUFrame->setGeometry(220,110,770,460);
    ui->CPUFrame->setVisible(true);
    ui->MemFrame->setGeometry(220,110,770,460);
    ui->MemFrame->setVisible(false);
    ui->NetFrame->setGeometry(220,110,770,460);
    ui->NetFrame->setVisible(false);

    ui->ProcessTable->setGeometry(20,100,970,470);
    ui->ProcessTable->setVisible(false);
    ui->ProcessTable->setSortingEnabled(true);

    ProcessViewModel *pv = new ProcessViewModel(this,&ProcessInfo);
    ui->ProcessTable->setModel(pv);
    ui->ProcessTable->setItemDelegateForColumn(1,new ProgressBarDelegate(this));
    ui->ProcessTable->setItemDelegateForColumn(2,new ProgressBarDelegate(this));
    this->pv = pv;
}

/*
 * switch to system state
*/
void MainWindow::on_pushButton_clicked()
{

    ui->CPUInfoButton->setVisible(true);
    ui->MemInfoButton->setVisible(true);
    ui->NetworkInfoButton->setVisible(true);

    ui->line->setVisible(true);

    ui->CPUFrame->setVisible(true);
    ui->NetFrame->setVisible(false);
    ui->MemFrame->setVisible(false);

    ui->ProcessTable->setVisible(false);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->CPUInfoButton->setVisible(false);
    ui->MemInfoButton->setVisible(false);
    ui->NetworkInfoButton->setVisible(false);

    ui->line->setVisible(false);

    ui->CPUFrame->setVisible(false);
    ui->NetFrame->setVisible(false);
    ui->MemFrame->setVisible(false);

    ui->ProcessTable->setVisible(true);
}

void MainWindow::on_CPUInfoButton_clicked()
{
    ui->CPUFrame->setVisible(true);
    ui->MemFrame->setVisible(false);
    ui->NetFrame->setVisible(false);

}

void MainWindow::on_MemInfoButton_clicked()
{
    ui->CPUFrame->setVisible(false);
    ui->MemFrame->setVisible(true);
    ui->NetFrame->setVisible(false);

}

void MainWindow::on_NetworkInfoButton_clicked()
{
    ui->CPUFrame->setVisible(false);
    ui->MemFrame->setVisible(false);
    ui->NetFrame->setVisible(true);
}

//GetPidList to read
QList<QString> GetPidList(){
    QList<QString> pidList;
    QDir dir("/proc");
    QFileInfoList list = dir.entryInfoList(QDir::Dirs,QDir::Name);
    qDebug()<<"filelist length is:"<<list.length()<<endl;
    for(QFileInfo fileinfo:list){
        if(fileinfo.fileName()=="."||fileinfo.fileName()=="..")
            continue;
        bool ok = true;
        fileinfo.fileName().toInt(&ok,10);
        if(!ok){
            continue;
        }
        pidList.append(fileinfo.fileName());
    }
    return pidList;
}

bool update_process_cpu_usage(ProcessInfoModel & pim, long long cputotal){
    QFile file("/proc/"+pim.Pid+"/stat");
    if(!file.open(QFile::ReadOnly| QFile::Text)){
        qDebug()<<"update_process_cpu_usage, file /proc/"<<pim.Pid<<"/stat open fialed"<<endl;
        return false;
    }
    QTextStream in(&file);
    QString str = in.readAll();
    file.close();
    QStringList qslst = str.trimmed().split(' ');
    if(qslst.length()<17){
        file.close();
        qDebug()<<"update_process_cpu_usage,qslst split result not true!"
               <<"str is"<<str<<"qslst length is:"<<qslst.length()<<endl;
        return false;
    }
    long long sum = qslst[13].toLongLong()+qslst[14].toLongLong()+
            qslst[15].toLongLong()+qslst[16].toLongLong();

    pim.lastcpu = pim.nowcpu;
    pim.nowcpu = sum;
    //figure
    pim.CPUUsage = 1.0*(pim.nowcpu-pim.lastcpu)/cputotal;
    if(pim.CPUUsage>0.99) pim.CPUUsage = 0.8;
    return true;
}

bool update_process_mem_rate(ProcessInfoModel & pim, int memtotal){
    QFile file("/proc/"+pim.Pid+"/status");
    if(!file.open(QFile::ReadOnly| QFile::Text)){
        qDebug()<<"update_process_cpu_usage, file /proc/"<<pim.Pid<<"/status open fialed"<<endl;
        return false;
    }
    QTextStream in(&file);
    QStringList ls = in.readAll().trimmed().split('\n');
    file.close();
    bool ok = false;
    int memNum = 0;
    for (int i = 0;i<ls.length();i++) {
        if(ls[i].trimmed().contains("VmRSS")){
            QString str = ls[i].trimmed().split(":")[1].trimmed();
            memNum = str.split(' ')[0].trimmed().toInt();
            ok = true;
            break;
        }
    }
    if(ok==false) return false;
    pim.MemUsage = 1.0*memNum/memtotal;
    return true;
}

bool update_process_disk_speed(ProcessInfoModel & pim, double TimeScale){
    QFile file("/proc/"+pim.Pid+"/io");
    if(!file.open(QFile::ReadOnly| QFile::Text)){
        //qDebug()<<"update_process_cpu_usage, file /proc/"<<pim.Pid<<"/io open failed"<<endl;
        return false;
    }
    QTextStream in(&file);
    QStringList ls = in.readAll().trimmed().split('\n');
    file.close();
    //qDebug()<<"ls:"<<endl<<ls<<endl;
    long long iototal = 0;
    bool ok = false;
    for (int i = 0;i<ls.length();i++) {
        if(ls[i].contains("read_bytes")){
            long long num = ls[i].split(':')[1].trimmed().toLongLong();
            iototal += num;
            ok = true;
            continue;
        }
        else if(ls[i].contains("write_bytes")){
            long long num = ls[i].split(':')[1].trimmed().toLongLong();
            iototal += num;
            ok = true;
            continue;
        }
    }
    if(ok==false) return false;

    pim.lastio = pim.nowio;
    pim.nowio = iototal;

    pim.DiskReadSpeed = 1.0*(pim.nowio-pim.lastio)/(TimeScale/1000);
    return true;
}

bool update_process_cmd(ProcessInfoModel & pim){
    QFile file("/proc/"+pim.Pid+"/cmdline");
    if(!file.open(QFile::ReadOnly|QFile::Text)){
        qDebug()<<"update_process_net_rate, file /proc/"<<pim.Pid<<"/net/dev open failed"<<endl;
        return false;
    }
    QTextStream in(&file);
    QString str = in.readLine();
    pim.CMD = str;
    return true;
}

bool update_process_thread(ProcessInfoModel & pim){
    QDir dir("/proc/"+pim.Pid+"/task");
    QFileInfoList list = dir.entryInfoList(QDir::Dirs,QDir::Name);
    pim.TidList.clear();
    //qDebug()<<"filelist length is:"<<list.length()<<endl;
    for(QFileInfo fileinfo:list){
        if(fileinfo.fileName()=="."||fileinfo.fileName()=="..")
            continue;
        bool ok = true;
        fileinfo.fileName().toInt(&ok,10);
        if(!ok){
            break;
        }
        pim.TidList.append(fileinfo.fileName());
    }
    return true;
}


int getIndex(QString pid, QList<ProcessInfoModel> &list){
    for(int i = 0;i<list.length();i++){
        if(pid == list.at(i).Pid){
            return i;
        }
    }
    return -1;
}

void MainWindow::UpdateProcessInfoList(QList<ProcessInfoModel> &list){

    QList<ProcessInfoModel> oldlist = list;
    QList<QString> pidList = GetPidList();
    list.clear();

    for(QString pid : pidList){
        int index = getIndex(pid,oldlist);
        if(index ==-1){
            ProcessInfoModel pim;
            pim.Pid = pid;
            list.append(pim);
        }
        else {
            list.append(oldlist[index]);
        }
    }
    UpdateProcessInfo(list);
    return;
}

int GetCPUTotal(QList<ProcessInfoModel> &list){
    int total = 0;
    for(ProcessInfoModel pim : list){
        total += pim.nowcpu-pim.lastcpu;
    }
    return total;
}

void MainWindow::UpdateProcessInfo(QList<ProcessInfoModel> &list){
    int i = 0;
    while(i<list.length()){
        ProcessInfoModel pim = list[i];
        if(update_process_disk_speed(pim,NetInfo.TimeScale)){
            list[i] = pim;
            i++;
        }
        else
            list.removeAt(i);
    }

    i = 0;
    while (i<list.length()) {
        ProcessInfoModel pim = list[i];
        if(update_process_mem_rate(pim,MemInfo.MemSize)){
            list[i] = pim;
            i++;
        }
        else
            list.removeAt(i);
    }


    i = 0;
    while(i<list.length()){
        ProcessInfoModel pim = list[i];
        if(update_process_cmd(pim)){
            list[i] = pim;
            i++;
        }
        else
            list.removeAt(i);
    }

    i = 0;
    int total = GetCPUTotal(list);
    while(i<list.length()){
        ProcessInfoModel pim = list[i];
        if(update_process_cpu_usage(pim,total)){
            list[i] = pim;
            i++;
        }
        else
            list.removeAt(i);
    }

    i = 0;
    while(i<list.length()){
        ProcessInfoModel pim = list[i];
        if(update_process_thread(pim)){
            list[i] = pim;
            i++;
        }
        else
            list.removeAt(i);
    }
    return;
}


void MainWindow::Fresh(){

    this->CPUInfo.Update();
    this->MemInfo.Update();
    this->NetInfo.Update();
    UpdateProcessInfoList(this->ProcessInfo);
    qDebug()<<"Fresh, ProcessInfo is"<<ProcessInfo.length()<<endl;
    emit this->pv->layoutChanged();
    emit this->pv->dataChanged(pv->index(0,0),pv->index(ProcessInfo.length()-1,1));


    //cpu attr
    QString cpuUsageStr = ui->cpuUsageLabel->text().split('\n')[0]+"\n"+
            QString::asprintf("%.2lf",CPUInfo.CPUUsage*100)+"%";
    ui->cpuUsageLabel->setText(cpuUsageStr);

    QString cpuSpeedStr = ui->cpuSpeedLabel->text().split('\n')[0]+"\n"+
            QString::asprintf("%.2lf",CPUInfo.CPUSpeed)+"MHz";
    ui->cpuSpeedLabel->setText(cpuSpeedStr);

    QString LogProStr = ui->cpuLogicProcessLabel->text().split('\n')[0]+"\n"+
            QString::number(CPUInfo.LogProceNum);
    ui->cpuLogicProcessLabel->setText(LogProStr);

    QString PhyProStr = ui->cpuPhysicalProcessLabel->text().split('\n')[0]+"\n"+
            QString::number(CPUInfo.PhyProcNum)+","+QString::number(CPUInfo.PhyCoreNum);
    ui->cpuPhysicalProcessLabel->setText(PhyProStr);

    QString ProcessNumStr = ui->cpuProcudureLabel->text().split('\n')[0]+"\n"+
            QString::number(CPUInfo.ProcNum);
    ui->cpuProcudureLabel->setText(ProcessNumStr);

    QString ProMaxNumStr = ui->cpuMaxProcessLabel->text().split('\n')[0]+"\n"+
            QString::number(CPUInfo.ProcMaxNum);
    ui->cpuMaxProcessLabel->setText(ProMaxNumStr);

    //mem attr
    QString MemTotal = ui->MemTotalLabel->text().split('\n')[0]+"\n"+
            QString::number(MemInfo.MemSize/1000)+"MB";
    ui->MemTotalLabel->setText(MemTotal);
    QString FreeMem = ui->MemFreeLabel->text().split('\n')[0]+"\n"+
            QString::number(MemInfo.FreeMemSize/1000)+"MB";
    ui->MemFreeLabel->setText(FreeMem);
    QString Usage = ui->MemUsageLabel->text().split('\n')[0]+"\n"+
            QString::asprintf("%.2lf",MemInfo.Usage*100)+"%";
    ui->MemUsageLabel->setText(Usage);

    QString Buffers = ui->MemBufferLabel->text().split('\n')[0]+"\n"+
            QString::asprintf("%.3lf",1.0*MemInfo.BufferSize/1000)+"MB";
    ui->MemBufferLabel->setText(Buffers);

    QString Cached = ui->MemCachedLabel->text().split('\n')[0]+"\n"+
            QString::asprintf("%.3lf",1.0*MemInfo.CachedSize/1000)+"MB";
    ui->MemCachedLabel->setText(Cached);

    QString Swap = ui->MemSwapSizeLabel->text().split('\n')[0]+"\n"+
            QString::asprintf("%.3lf",1.0*MemInfo.SwapSize/1000)+"MB";
    ui->MemSwapSizeLabel->setText(Swap);

    QString FreeSwap = ui->MemSwapFreeLabel->text().split('\n')[0]+"\n"+
            QString::asprintf("%.3lf",1.0*MemInfo.FreeSwapSize/1000)+"MB";
    ui->MemSwapFreeLabel->setText(FreeSwap);

    QString PageTableSize = ui->MemPageSizeLabel->text().split('\n')[0]+"\n"+
            QString::number(MemInfo.PageTableSize)+"kB";
    ui->MemPageSizeLabel->setText(PageTableSize);


    //net attr
    QString DownloadSpeed = ui->NetDownloadLabel->text().split('\n')[0]+"\n"+
            QString::asprintf("%.2lf",NetInfo.DownloadSpeed)+"kB/s";
    ui->NetDownloadLabel->setText(DownloadSpeed);

    QString UploadSpeed = ui->NetUploadLabel->text().split('\n')[0]+"\n"+
            QString::asprintf("%.2lf",NetInfo.UploadSpeed)+"kB/s";
    ui->NetUploadLabel->setText(UploadSpeed);

    QString IP = ui->NetIPLabel->text().split('\n')[0]+"\n"+
            NetInfo.IPv6;
    ui->NetIPLabel->setText(IP);

    QString ErrNum = ui->NetErrLabel->text().split('\n')[0]+"\n"+
            QString::number(NetInfo.ErrorNum);
    ui->NetErrLabel->setText(ErrNum);

    QString TCPNum = ui->NetTCPNumLabel->text().split('\n')[0]+"\n"+
            QString::number(NetInfo.TCPEstab);
    ui->NetTCPNumLabel->setText(TCPNum);

    QString UDPDatagram = ui->NetUDPDatagramLabel->text().split('\n')[0]+"\n"+
            QString::asprintf("%.2lf",NetInfo.UDPDatagramSpeed)+"pkt/s";
    ui->NetUDPDatagramLabel->setText(UDPDatagram);
    return;

}


