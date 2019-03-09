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

private:
    Ui::regularfile *ui;
};

#endif // REGULARFILE_H
