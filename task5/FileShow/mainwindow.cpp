#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../filesystem/models.h"
#include "../syscall/sysdirectory.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{



    ui->setupUi(this);
}

int MainWindow::fresh(){
    struct dirent dir[32];
    int length;
    sysGetAllDirectory(dir, &length);



    return 0;
}



MainWindow::~MainWindow()
{
    delete ui;
}
