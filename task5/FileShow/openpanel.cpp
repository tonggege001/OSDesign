#include "openpanel.h"
#include "ui_openpanel.h"
#include "../syscall/sysdirectory.h"
#include "QDebug"

OpenPanel::OpenPanel(QWidget *parent, QString filename) :
    QDialog(parent),
    ui(new Ui::OpenPanel)
{
    ui->setupUi(this);

    this->ui->filename_label->setText(filename);
    char * con = (char *)malloc(sizeof(char) * 1024 * 1024);
    char name[50];
    strcpy(name, filename.toStdString().c_str());
    sysReadFile(name,con,5*1024*1024);
    QString content = QString(QLatin1String(con));
    this->ui->textEdit->setText(content);
    free(con);
}



OpenPanel::~OpenPanel()
{
    delete ui;
}

void OpenPanel::on_buttonBox_accepted()
{
    char filename[50];
    char * con = (char *)malloc(5*1024*1024*sizeof(char));
    strcpy(filename, ui->filename_label->text().toStdString().c_str());
    strcpy(con,ui->textEdit->toPlainText().toStdString().c_str());
    sysWriteFile(filename,con);
    emit changed();
    free(con);
}
