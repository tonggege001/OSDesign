#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTimer>
#include<QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),count(0),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerUpdate(void)
{
    count++;
    if(count==10) count=0;
    char buf[4];
    sprintf(buf,"%d",count);
    ui->label_2->setText(buf);
}
