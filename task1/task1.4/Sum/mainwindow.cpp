#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTimer>
#include<QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),sum(0),num(0),
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
    num++;
    if(num>100){
        num = 0;
        sum = 0;
    }
    else{
        sum += num;
    }
    char buf[20];
    sprintf(buf,"%d",sum);
    ui->label_2->setText(buf);
}
