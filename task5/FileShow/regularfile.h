#ifndef REGULARFILE_H
#define REGULARFILE_H

#include <QWidget>

namespace Ui {
class regularfile;
}

class regularfile : public QWidget
{
    Q_OBJECT

public:
    QString filename;
    QString owner;
    QString size;
    QString createtime;


public:
    explicit regularfile(QWidget *parent = nullptr);
    ~regularfile();
    void fresh();

    void setAttr(QString filename, QString owner, QString size, QString createTime);

signals:
        void clicked();
        void changed();

private:
    Ui::regularfile *ui;
    void mouseDoubleClickEvent(QMouseEvent *event);

private slots:
    void openslot();
    void renameslot();
    void deleteslot();
    void Change();

protected:

};

#endif // REGULARFILE_H
