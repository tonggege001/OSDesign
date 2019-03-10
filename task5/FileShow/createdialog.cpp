#include "createdialog.h"
#include "ui_createdialog.h"

#include <QMessageBox>
#include <QDebug>
CreateDialog::CreateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateDialog)
{
    ui->setupUi(this);
}

CreateDialog::~CreateDialog()
{
    delete ui;
}

void CreateDialog::on_buttonBox_accepted()
{
    qDebug()<<"on_buttonBox_accepted";
    QString name = this->ui->lineEdit->text().trimmed();
    QString owner = this->ui->lineEdit_2->text().trimmed();
    if(name == ""){
        QMessageBox::about(this,"文件名不能为空","文件名不能为空");
        return;
    }
    if(owner == ""){
        owner = "Default";
    }
    emit createok(name,owner);
}
