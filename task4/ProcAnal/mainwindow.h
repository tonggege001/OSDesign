#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cpuinfomodel.h"
#include "meminfomodel.h"
#include "netinfomodel.h"
#include "processinfomodel.h"

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
    ProcessViewModel * pv;

    CPUInfoModel CPUInfo;
    MemInfoModel MemInfo;
    NetInfoModel NetInfo;
    QList<ProcessInfoModel> ProcessInfo;


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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_CPUInfoButton_clicked();

    void on_MemInfoButton_clicked();

    void on_NetworkInfoButton_clicked();




};

#endif // MAINWINDOW_H
