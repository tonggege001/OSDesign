#include "TGGdirectory.h"
#include "ui_directory.h"

TGGdirectory::TGGdirectory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TGGdirectory)
{
    ui->setupUi(this);
    filecount = 0;
    totalSize = 0;
    spaceSize = 0;
}

TGGdirectory::~TGGdirectory()
{
    delete ui;
}
