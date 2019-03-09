#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMenu>
#include <QSplineSeries>
#include "cpuinfomodel.h"
#include "meminfomodel.h"
#include "netinfomodel.h"
#include "processinfomodel.h"
#include<QtCharts>

using namespace QtCharts;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;

public:
    //table model
    ProcessViewModel *      pv;
    CPUInfoModel            CPUInfo;
    MemInfoModel            MemInfo;
    NetInfoModel            NetInfo;
    QList<ProcessInfoModel> ProcessInfo;
    QMenu *                 menu;
    QAction *               action;
    QPoint                  pos;            //结束进程时找到位置
    //qcharts
    QSplineSeries *         series;
    QChart *                qchart;
    QChartView *            chartView;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //construct facade
    void MakeMainWindowLayout();
    void MakeMainWindowBackground();
    void MakeMainWindowWidget();
    void UpdateProcessInfoList(QList<ProcessInfoModel> &list);
    void UpdateProcessInfo(QList<ProcessInfoModel> &list);
public slots:
    void Fresh();
    void slotContextMenu(QPoint pos);
    void StopProcess();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_CPUInfoButton_clicked();

    void on_MemInfoButton_clicked();

    void on_NetworkInfoButton_clicked();




    void on_CPU_anal_button_clicked();
};

#endif // MAINWINDOW_H
