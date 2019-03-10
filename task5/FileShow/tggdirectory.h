#ifndef TGGDIRECTORY_H
#define TGGDIRECTORY_H

#include <QWidget>

namespace Ui {
class TGGdirectory;
}

class TGGdirectory : public QWidget
{
    Q_OBJECT
public:
    int filecount;
    int Space;
    int Total;

public:
    explicit TGGdirectory(QWidget *parent = nullptr);
    ~TGGdirectory();

private:
    Ui::TGGdirectory *ui;

    void mouseDoubleClickEvent(QMouseEvent *event);

signals:
    void clicked();
};

#endif // TGGDIRECTORY_H
