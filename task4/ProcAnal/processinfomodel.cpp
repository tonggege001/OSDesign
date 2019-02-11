#include "processinfomodel.h"
#include <QApplication>
#include<QStyledItemDelegate>

ProcessInfoModel::ProcessInfoModel()
{
    CPUUsage = 0;
    MemUsage = 0;
    DiskReadSpeed = 0;

    lastcpu = 0;
    nowcpu = 0;
    lastio = 0;
    nowio = 0;
}


QString ProcessInfoModel::TidListToQString() const
{
    QString a;
    for(QString str:this->TidList){
        a = a+str+" ";
    }
    return a;
}


ProcessViewModel::ProcessViewModel(QObject *parent, QList<ProcessInfoModel> *data):
    QAbstractTableModel(parent),dataList(data){}

int ProcessViewModel::rowCount(const QModelIndex &parent) const{
    if(dataList==nullptr) return 0;
    return dataList->length();
}

int ProcessViewModel::columnCount(const QModelIndex &parent) const{
    return 6;
}

QVariant ProcessViewModel::data(const QModelIndex &index, int role) const{
    if(role!=Qt::DisplayRole) return QVariant();
    const ProcessInfoModel & processinfo = (*dataList)[index.row()];
    switch(index.column()){
    case 0:return processinfo.Pid;
    case 1:return processinfo.CPUUsage;
    case 2:return processinfo.MemUsage;
    case 3:return QString::asprintf("%.2lf",processinfo.DiskReadSpeed/(1024 * 1024))+"Mb/s";
    case 4:return processinfo.CMD;
    case 5:return processinfo.TidListToQString();
    default:return QVariant();
    }
}

QVariant ProcessViewModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole && role != Qt::EditRole) return QVariant();
    if(orientation == Qt::Orientation::Horizontal){
        switch (section) {
        case 0:
            return "PID";
        case 1:
            return "CPU";
        case 2:
            return "内存";
        case 3:
            return "磁盘";
        case 4:
            return "启动命令";
        case 5:
            return "线程";
        default:
            return QVariant();
        }
    }
    else {
        return section+1;
    }

}



ProgressBarDelegate::ProgressBarDelegate(QObject *parent):
    QStyledItemDelegate (parent){}

void ProgressBarDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const{
    double progress = index.model()->data(index,Qt::DisplayRole).toDouble();
    QStyleOptionProgressBar prgrsbar;
    prgrsbar.rect = option.rect;
    prgrsbar.minimum = 0;
    prgrsbar.maximum = 100;
    prgrsbar.progress = int(progress*100);
    prgrsbar.text = QString::number(int(progress*100))+"%";
    prgrsbar.textVisible = true;
    QApplication::style()->drawControl(QStyle::CE_ProgressBar,
                                       &prgrsbar, painter);
}







