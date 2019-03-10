#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <QWidget>

namespace Ui {
class TGGdirectory;
}

class TGGdirectory : public QWidget
{
    Q_OBJECT
public:
    int filecount;
    int totalSize;
    int spaceSize;

public:
    explicit TGGdirectory(QWidget *parent = nullptr);
    ~TGGdirectory();

private:
    Ui::TGGdirectory *ui;
};

#endif // DIRECTORY_H
