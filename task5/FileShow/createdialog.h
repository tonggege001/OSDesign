#ifndef CREATEDIALOG_H
#define CREATEDIALOG_H

#include <QDialog>

namespace Ui {
class CreateDialog;
}

class CreateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateDialog(QWidget *parent = nullptr);
    ~CreateDialog();



private slots:
    void on_buttonBox_accepted();

private:
    Ui::CreateDialog *ui;

signals:
    void createok(QString, QString);
};

#endif // CREATEDIALOG_H
