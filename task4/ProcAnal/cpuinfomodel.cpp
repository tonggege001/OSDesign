#include "cpuinfomodel.h"

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>


CPUInfoModel::CPUInfoModel()
{
    CPUUsage = 0;
    CPUSpeed = 0;
    LogProceNum = 0;
    PhyProcNum = 0;
    PhyCoreNum = 0;
    ProcNum = 0;
    ProcMaxNum = 0;

    lastCpuTotal = 0;
    lastCpuIdle = 0;
    nowCpuTotal = 0;
    nowCpuIdle = 0;

    Update();
}

void CPUInfoModel::_update_cpu_usage()
{
    QFile file("/proc/stat");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"_update_cpu_usage,file can't open,error,err="<<file.error()<<endl;
        return;
    }

    QTextStream in(&file);
    QString str = in.readLine();
    str = str.mid(5,-1);
    qDebug()<<"_update_cpu_usage, str is "<<endl<<str<<endl;
    QStringList strArr = str.split(' ');
    if (strArr.length()<=0){
        qDebug()<<"_update_cpu_usage,in.readLine split error, data is "<<str<<endl;
        file.close();
        return;
    }
    file.close();
    long long total=0,idle = 0;

    for (int i = 0;i<strArr.length();i++) {
        total +=strArr[i].toLongLong();
        if (i==3)
            idle += strArr[i].toLongLong();
    }

    this->lastCpuTotal = this->nowCpuTotal;
    this->lastCpuIdle = this->nowCpuIdle;
    this->nowCpuTotal = total;
    this->nowCpuIdle = idle;

    //figure
    total = nowCpuTotal-lastCpuTotal;
    idle = nowCpuIdle-lastCpuIdle;

    qDebug()<<"total:"<<total<<"idle:"<<idle<<endl;
    this->CPUUsage = 1.0*(total-idle)/total;

}

void CPUInfoModel::_update_procmax()
{
    QFile file("/proc/sys/kernel/pid_max");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug()<<"_update_procmax, file open error, err = "<<file.error()<<endl;
        return;
    }
    QTextStream in(&file);
    QString str = in.readLine();
    ProcMaxNum = str.toInt();
    file.close();

}

void CPUInfoModel::_update_attr()
{
    QFile file("/proc/cpuinfo");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qInfo()<<"_update_attr, file open error, err = "<<file.error()<<endl;
        return;
    }
    QTextStream in(&file);
    QString str = in.readAll().trimmed();
    qDebug()<<"_update_attr, str is"<<endl<<str<<endl;
    QStringList strArr = str.split("\n\n");
    file.close();

    QVector<QMap<QString,QString>> mapVec;
    for (int i=0;i<strArr.length();i++) {   //initialize mapVec
        mapVec.append(QMap<QString,QString>());
    }

    for (int i=0;i<strArr.length();i++) {
        QStringList slist = strArr[i].split('\n');
        for(QString subs:slist){
            QStringList pair = subs.split(':');
            if (pair.length()!=2) continue;
            mapVec[i].insert(pair[0].trimmed(),pair[1].trimmed());
        }
    }

    LogProceNum = strArr.length();

    CPUSpeed = 0;
    for(QMap<QString,QString> map:mapVec){
        CPUSpeed += map["cpu MHz"].toDouble();
    }
    CPUSpeed /= strArr.length();

    QMap<QString,QString> phymap;
    for (QMap<QString,QString> map:mapVec) {
        phymap[map["physical id"]] = "0";
    }
    PhyProcNum = phymap.size();
    PhyCoreNum = mapVec[0]["cpu cores"].toInt();

    QDir dir("/proc");
    if(!dir.exists())
        return;
    QFileInfoList list = dir.entryInfoList(QDir::Dirs,QDir::Name);
    qDebug()<<"filelist length is:"<<list.length()<<endl;
    ProcNum = 0;
    for(QFileInfo fileinfo:list){
        if(fileinfo.fileName()=="."||fileinfo.fileName()=="..")
            continue;
        //qDebug()<<fileinfo<<endl;
        bool ok = true;
        fileinfo.fileName().toInt(&ok,10);
        if(!ok){
            break;
        }
        ProcNum++;
    }
    return;
}

void CPUInfoModel::Update()
{
    _update_cpu_usage();
    _update_procmax();
    _update_attr();
}

long long CPUInfoModel::GetCpuTotal()
{
    return this->nowCpuTotal;
}

long long CPUInfoModel::GetCpuIdle()
{
    return this->nowCpuIdle;
}






