#ifndef OPENPANEL_H
#define OPENPANEL_H

#include <QDialog>

namespace Ui {
class OpenPanel;
}

class OpenPanel : public QDialog
{
    Q_OBJECT

public:
    explicit OpenPanel(QWidget *parent = nullptr, QString filename = "");
    ~OpenPanel();

private:
    Ui::OpenPanel *ui;

signals:
    void changed();
private slots:
    void on_buttonBox_accepted();
};

#endif // OPENPANEL_H
