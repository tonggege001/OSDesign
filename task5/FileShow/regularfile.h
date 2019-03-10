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

    void mousePressEvent(QMouseEvent *e);

private slots:
    void openslot();
    void renameslot();
    void deleteslot();

protected:

};

#endif // REGULARFILE_H
