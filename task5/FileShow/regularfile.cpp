#include "regularfile.h"
#include "ui_regularfile.h"
#include "openpanel.h"
#include <QAction>
#include <QDateTime>
#include <QInputDialog>
#include <qevent.h>
#include <QMessageBox>
#include "../syscall/sysdirectory.h"
#include<QDebug>
regularfile::regularfile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::regularfile)
{
    ui->setupUi(this);
    filename = "";
    owner = "";
    size = "";
    createtime = "";
    QAction * openAction = new QAction("打开", nullptr);
    QAction * renameAction = new QAction("重命名",nullptr);
    QAction * deleteAction = new QAction("删除",nullptr);

    connect(openAction,SIGNAL(triggered()),this,SLOT(openslot()));
    connect(renameAction, SIGNAL(triggered()), this, SLOT(renameslot()));
    connect(deleteAction, SIGNAL(triggered()), this, SLOT(deleteslot()));

    addAction(openAction);
    addAction(renameAction);
    addAction(deleteAction);
}

regularfile::~regularfile()
{
    delete ui;
}
void regularfile::setAttr(QString filename, QString owner, QString size, QString createTime){
    this->filename = filename;
    this->owner = owner;
    this->size = size;
    this->createtime = createTime;
}


//double clicked
void regularfile::mouseDoubleClickEvent(QMouseEvent * event){
    qDebug()<<"mouseDoubleClickEvent"<<filename<<endl;
    QString filename = this->filename;
    OpenPanel *op = new OpenPanel(this,filename);
    connect(op,SIGNAL(changed()),this,SLOT(Change()));
    op->show();
}

void regularfile::openslot()
{
}

void regularfile::renameslot()
{
    QString name = QInputDialog::getText(this,"输入名称","输入名称:");
    if(name.trimmed()==""){
        QMessageBox::about(this,"错误","名称输入非法");
        return;
    }
    else {
        char filename_[50];
        char name_[50];
        strcpy(filename_, this->filename.toStdString().c_str());
        strcpy(name_, name.toStdString().c_str());
        sysRename(filename_, name_);
        this->filename = name;
        emit this->changed();
    }

}

void regularfile::deleteslot()
{
    char buf[50];
    strcpy(buf,this->filename.toStdString().c_str());
    qDebug()<<this->filename;
    sysDeleteFile(buf);
    emit this->changed();

}

void regularfile::Change()
{
    emit changed();
}

void regularfile::fresh()
{
    ui->filename->setText(this->filename);
    QString tip = "owner: "+this->owner+"\nfile size: "+this->size+
            "\ncreate_time: "+createtime;
    this->setToolTip(tip);

}

