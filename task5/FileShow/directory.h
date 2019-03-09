#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <QWidget>

namespace Ui {
class directory;
}

class directory : public QWidget
{
    Q_OBJECT

public:
    explicit directory(QWidget *parent = nullptr);
    ~directory();

private:
    Ui::directory *ui;
};

#endif // DIRECTORY_H
