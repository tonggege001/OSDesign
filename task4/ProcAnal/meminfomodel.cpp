#include "meminfomodel.h"

#include <QFile>
#include<QDebug>
MemInfoModel::MemInfoModel()
{
    MemSize = 0;
    FreeMemSize = 0;
    Usage = 0;
    BufferSize = 0;
    CachedSize = 0;
    SwapSize = 0;
    FreeSwapSize = 0;
    PageTableSize = 0;
}


void MemInfoModel::Update(){
    QFile file("/proc/meminfo");
    if(!file.open(QFile::ReadOnly|QFile::Text)){
        qDebug()<<"MemInfoModel->Update() error, file can't open!, filename is /proc/meminfo"<<endl;
        return;
    }
    QTextStream in(&file);
    QString info = in.readAll().trimmed();
    qInfo()<<info<<endl;
    file.close();
    QStringList strList = info.split('\n');
    QMap<QString,QString> infoMap;

    for(QString str:strList){
        QStringList ql = str.split(':');
        if(ql.length()!=2) continue;
        QString res = ql[1].trimmed().split(' ')[0];
        infoMap.insert(ql[0].trimmed(),res);
    }
    this->MemSize = infoMap["MemTotal"].toInt();
    this->FreeMemSize = infoMap["MemFree"].toInt();
    this->Usage = 1.0*(MemSize-FreeMemSize)/MemSize;
    this->BufferSize = infoMap["Buffers"].toInt();
    this->CachedSize = infoMap["Cached"].toInt();
    this->SwapSize = infoMap["SwapTotal"].toInt();
    this->FreeSwapSize = infoMap["SwapFree"].toInt();
    this->PageTableSize = infoMap["Hugepagesize"].toInt();
    return;

}











