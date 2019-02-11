#include "netinfomodel.h"

#include <QFile>
#include <QDebug>

NetInfoModel::NetInfoModel()
{
    DownloadSpeed = 0;
    UploadSpeed = 0;
    IPv6 = "";
    ErrorNum = 0;
    TCPEstab = 0;
    UDPDatagramSpeed = 0;
    lastDownload = 0;
    nowDownload = 0;
    lastUpload = 0;
    nowUpload = 0;
    lastUDP = 0;
    nowUDP = 0;
    TimeScale = 1;
}

void NetInfoModel::_update_dev()
{
    QFile file("/proc/net/dev");
    if(!file.open(QFile::ReadOnly|QFile::Text)){
        qDebug()<<"_update_dev, can't open file,filename is /proc/net/dev"<<endl;
        return;
    }
    QTextStream in(&file);
    in.readLine();in.readLine();
    QList<QList<int>> infotab;

    QStringList datalist = in.readAll().trimmed().split('\n');
    file.close();

    for (int i = 0;i<datalist.length();i++) {
        if(datalist[i].contains("lo")) continue;

        infotab.append(QList<int>());
        qDebug()<<"_update_dev, datalist[i] is:"<<datalist[i]<<endl;
        QString strArr = datalist[i].mid(datalist[i].indexOf(':')+1).trimmed();
        qDebug()<<"_update_dev, strArr is:"<<strArr<<endl;
        int up=0,down=0,errup=0,errdown=0,tmp;
        sscanf(strArr.toLatin1().data(),"%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",&up,&tmp,&errup,&tmp,&tmp,&tmp,&tmp,&tmp,
               &down,&tmp,&errdown,&tmp,&tmp,&tmp,&tmp,&tmp);
        qDebug()<<"up:"<<up<<"down:"<<down<<"errup:"<<errup<<"errdown:"<<errdown<<endl;
        infotab.last().append(up);
        infotab.last().append(down);
        infotab.last().append(errup+errdown);
    }

    lastUpload = nowUpload;
    lastDownload = nowDownload;

    ErrorNum = 0;
    nowDownload=nowUpload=0;
    for (int i = 0;i<infotab.length();i++) {
        nowUpload += infotab[i][0];
        nowDownload += infotab[i][1];
        ErrorNum += infotab[i][2];
    }
    qDebug()<<"lastDownload:"<<lastDownload<<"lastUpload:"<<lastUpload<<
              "nowDownload:"<<nowDownload<<"nowUpload:"<<nowUpload<<endl;
    //figure
    UploadSpeed = 1.0*(nowUpload-lastUpload)/TimeScale;
    DownloadSpeed = 1.0*(nowDownload-lastDownload)/TimeScale;
    return;
}

void NetInfoModel::_update_IP()
{
    QFile file("/proc/net/if_inet6");
    if(!file.open(QFile::ReadOnly|QFile::Text)){
        qDebug()<<"_update_IP, can't open file,filename is /proc/net/if_inet6"<<endl;
        return;
    }
    QTextStream in(&file);
    QStringList datalist = in.readAll().trimmed().split('\n');
    file.close();

    if(datalist.length()==1){   //no network
        this->IPv6 = "No Network";
        return;
    }

    for(QString str:datalist){
        QStringList ql = str.split(' ');
        if(ql[0]=="00000000000000000000000000000001")
            continue;

        //get the first eth or wth IP address
        this->IPv6 = ql[0].mid(0,4)+":"+ql[0].mid(4,4)+":"+ql[0].mid(8,4)+":"+
                ql[0].mid(12,4);
        break;
    }
    return;
}

void NetInfoModel::_update_snmp()
{
    QFile file("/proc/net/snmp");
    if(!file.open(QFile::ReadOnly|QFile::Text)){
        qDebug()<<"_update_snmp, cannot open /proc/net/snmp file"<<endl;
        return;
    }
    QTextStream in(&file);
    in.readLine();in.readLine();in.readLine();
    in.readLine();in.readLine();in.readLine();
    in.readLine();
    QString strTcp = in.readLine().mid(5); //TCP Msg
    qInfo()<<"_update_snmp, strTcp:"<<strTcp<<endl;
    in.readLine();
    QString strUdp = in.readLine().mid(5);  //UDP Msg
    qInfo()<<"_update_snmp,strUdp:"<<strUdp<<endl;
    file.close();
    this->TCPEstab = strTcp.split(' ')[8].toInt();

    this->lastUDP = this->nowUDP;
    this->nowUDP = strUdp.split(' ')[0].toInt()+strUdp.split(' ')[3].toInt();
    this->UDPDatagramSpeed = 1.0*(nowUDP-lastUDP)/TimeScale;


}

void NetInfoModel::Update()
{
    _update_dev();
    _update_IP();
    _update_snmp();
}


