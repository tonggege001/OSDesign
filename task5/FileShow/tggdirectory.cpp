
#include "tggdirectory.h"
#include "ui_tggdirectory.h"
#include <QDebug>
#include <qevent.h>
TGGdirectory::TGGdirectory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TGGdirectory)
{
    ui->setupUi(this);
    filecount = 0;
    Space = 0;
    Total = 0;
}

TGGdirectory::~TGGdirectory()
{
    delete ui;
}

void TGGdirectory::mouseDoubleClickEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if(x>=this->pos().rx() && x<= this->pos().rx()+100){
        if(y>=this->pos().ry() && y<= this->pos().y()+100){
            emit clicked();
        }
    }

}
