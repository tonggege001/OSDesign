#include "regularfile.h"
#include "ui_regularfile.h"

regularfile::regularfile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::regularfile)
{
    ui->setupUi(this);
    filename = "";
    owner = "";
    size = "";
    createtime = "";
}

regularfile::~regularfile()
{
    delete ui;
}
