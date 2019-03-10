#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tggdirectory.h"
#include <QMainWindow>
#include<regularfile.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    int state;          //0:dir  1:file

    QList<struct dirent > direntList;
    TGGdirectory * dir;
    QList<regularfile *> fileWidgetList;


    QMenu * menu;

    QAction * createAction;
    QAction * flushAction;
    QAction * attrAction;


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void InitFile();

    void LoadDirectory();
    void LoadFiles();
    void freshData();

public slots:
    void ContextMenu(QPoint p);
    void createFileOKSlot(QString name, QString owner);
private slots:
    void on_actionback_triggered();
    void on_click_dir();


    void createfileslot();
    void attrslot();
    void flushslot();
    void changedslot();

signals:

private:
    Ui::MainWindow *ui;

    //contextMenuEvent
};

#endif // MAINWINDOW_H
