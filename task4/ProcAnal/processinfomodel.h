#ifndef PROCESSINFOMODEL_H
#define PROCESSINFOMODEL_H

#include <QString>
#include <QList>
#include <QStyledItemDelegate>
#include <QApplication>

class ProcessInfoModel
{
public:
    QString     Pid;
    double      CPUUsage;
    double      MemUsage;
    double      DiskReadSpeed;
    QString     CMD;
    QList<QString> TidList;


    long long lastcpu;
    long long nowcpu;

    long long lastio;
    long long nowio;

    ProcessInfoModel();
    QString TidListToQString() const;

};


//进度条代理
class ProgressBarDelegate : public QStyledItemDelegate{
public:
    ProgressBarDelegate(QObject * parent = nullptr);
    // QAbstractItemDelegate interface
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};




class ProcessViewModel : public QAbstractTableModel{
private:
    QList<ProcessInfoModel> * dataList;

    // QAbstractItemModel interface
public:
    ProcessViewModel(QObject * parent = nullptr,QList<ProcessInfoModel> *data = nullptr);

    int rowCount(const QModelIndex &parent) const;

    int columnCount(const QModelIndex &parent) const;

    QVariant data(const QModelIndex &index, int role) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};





#endif // PROCESSINFOMODEL_H
