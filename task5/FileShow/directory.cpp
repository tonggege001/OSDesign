#include "directory.h"
#include "ui_directory.h"

directory::directory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::directory)
{
    ui->setupUi(this);
    filecount = 0;
    totalSize = 0;
    spaceSize = 0;
}

directory::~directory()
{
    delete ui;
}
