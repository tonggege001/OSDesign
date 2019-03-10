#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tggdirectory.h"
#include "createdialog.h"
#include <QDateTime>
#include <QDebug>
#include <QMenu>
#include <QMessageBox>
#include "../syscall/sysdirectory.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    state = 0;
    dir = nullptr;
    ui->setupUi(this);
    InitFile();


    connect(this->ui->centralWidget,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(ContextMenu(QPoint)));
    menu = new QMenu(this->ui->centralWidget);



    createAction = new QAction("创建",this->ui->centralWidget);
    flushAction = new QAction("刷新",this->ui->centralWidget);
    attrAction = new QAction("属性",this->ui->centralWidget);
    menu->addAction(createAction);
    menu->addAction(flushAction);
    menu->addAction(attrAction);
    connect(createAction, SIGNAL(triggered()), this, SLOT(createfileslot()));
    connect(flushAction,SIGNAL(triggered()),this,SLOT(flushslot()));
    connect(attrAction,SIGNAL(triggered()),this,SLOT(attrslot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitFile()
{
    freshData();
    LoadDirectory();

}

void MainWindow::LoadDirectory(){
    if(dir == nullptr)
        dir = new TGGdirectory(this);
    ui->gridLayout->removeWidget(dir);
    while(fileWidgetList.length()!=0){
        ui->gridLayout->removeWidget(fileWidgetList.at(0));
        regularfile * tmp = fileWidgetList.at(0);
        fileWidgetList.removeAt(0);
        delete tmp;
    }
    if(this->dir == nullptr){
        dir = new TGGdirectory(this);
    }

    dir->setToolTip("file length is "+QString::number(dir->filecount));
    this->ui->gridLayout->addWidget(dir);

    connect(dir,SIGNAL(clicked()),this,SLOT(on_click_dir()));
}

void MainWindow::LoadFiles(){
    ui->gridLayout->removeWidget(dir);
    delete dir;
    this->dir = nullptr;


    //remove old
    qDebug()<<"remove old"<<endl;
    while(fileWidgetList.length()!=0){
        ui->gridLayout->removeWidget(fileWidgetList.at(0));
        regularfile * tmp = fileWidgetList.at(0);
        fileWidgetList.removeAt(0);
        //delete tmp;
    }
    qDebug()<<"add new"<<endl;
    //add new
    for(struct dirent d:this->direntList){
        regularfile * reg = new regularfile(this->ui->gridLayoutWidget);
        reg->filename = d.name;
        reg->owner = d.owner;
        QDateTime time = QDateTime::fromTime_t(d.ctime);
        reg->createtime = time.toString();
        reg->size = QString::number(d.size);

        reg->fresh();
        this->fileWidgetList.append(reg);
        int num = this->ui->gridLayout->count();
        this->ui->gridLayout->addWidget(reg,num/10,num % 10);

        connect(reg,SIGNAL(changed()),this,SLOT(changedslot()));

    }

}

void MainWindow::freshData(){
    struct dirent dire[32];
    int length;
    if(this->dir== nullptr){
        this->dir = new TGGdirectory(this);
    }
    sysGetAllDirectory(dire,&length);
    dir->filecount = length;
    int Total = 50 * 1024;  //block num
    int Use = 0;
    for(int i = 0;i<length;i++){
        Use += dire[i].blockcount;
    }
    dir->Total = Total * 2 / 1024;
    dir->Space = (Total - Use) * 2 / 1024;
    this->direntList.clear();
    for(int i = 0;i<length;i++){
        this->direntList.append(dire[i]);

    }

}

void MainWindow::on_actionback_triggered()
{   this->freshData();
    if(state == 1){
        this->LoadDirectory();
        state = 0;
    }
    else{
        this->LoadFiles();
    }
}

void MainWindow::on_click_dir()
{
    state = 1;
    this->freshData();
    this->LoadFiles();
}

void MainWindow::ContextMenu(QPoint p)
{

    menu->exec(QCursor::pos());
}

void MainWindow::createfileslot()
{
    if(state == 0){
        QMessageBox::about(this,"提示","单级目录只能有一个主目录/ ，不能额外创建目录");
    }
    else{
        CreateDialog c;
        connect(&c,SIGNAL(createok(QString, QString)),this,SLOT(createFileOKSlot(QString, QString)));
        c.exec();

    }
}
void MainWindow::createFileOKSlot(QString name, QString owner)
{
    qDebug()<<"createFileOKSlot";
    char _name[100];
    char _owner[100];
    strcpy(_name,name.toStdString().c_str());
    strcpy(_owner,owner.toStdString().c_str());
    sysCreateFile(_name, _owner);
    this->freshData();
    this->LoadFiles();
}


void MainWindow::attrslot()
{
    if(state == 0){
        QString attr = "文件个数："+QString::number(dir->filecount)+
                "\n磁盘空间："+QString::number(dir->Total)+"MB\n"+
                "剩余空间："+QString::number(dir->Space)+"MB";
        QMessageBox::about(this,"磁盘属性",attr);
    }
    else {
        qDebug()<<"attrslot state == 1";
        QString attr = "Waiting......";
        QMessageBox::about(this,"文件属性",attr);
    }

}

void MainWindow::flushslot()
{
    this->freshData();
    if(state == 0){
        this->LoadDirectory();
    }
    else{
        this->LoadFiles();
    }

}

void MainWindow::changedslot()
{
    qDebug()<<"freshData"<<endl;
    this->freshData();
    if(state == 0){
        this->LoadDirectory();
    }
    else {
        qDebug()<<"changedslot before"<<endl;
        this->LoadFiles();
    }
}



