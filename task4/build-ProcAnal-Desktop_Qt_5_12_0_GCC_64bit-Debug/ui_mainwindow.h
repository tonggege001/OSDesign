/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QCommandLinkButton *CPUInfoButton;
    QCommandLinkButton *MemInfoButton;
    QCommandLinkButton *NetworkInfoButton;
    QFrame *line;
    QFrame *line_2;
    QFrame *CPUFrame;
    QWidget *gridLayoutWidget;
    QGridLayout *CPULayout;
    QLabel *cpuUsageLabel;
    QLabel *cpuPhysicalProcessLabel;
    QLabel *cpuLogicProcessLabel;
    QLabel *cpuSpeedLabel;
    QLabel *cpuProcudureLabel;
    QLabel *cpuMaxProcessLabel;
    QLabel *label_5;
    QFrame *MemFrame;
    QWidget *gridLayoutWidget_2;
    QGridLayout *MemLayout;
    QLabel *MemBufferLabel;
    QLabel *MemTotalLabel;
    QLabel *MemCachedLabel;
    QLabel *MemUsageLabel;
    QLabel *MemSwapSizeLabel;
    QLabel *MemFreeLabel;
    QLabel *MemSwapFreeLabel;
    QLabel *MemPageSizeLabel;
    QLabel *label_6;
    QFrame *NetFrame;
    QWidget *gridLayoutWidget_3;
    QGridLayout *NetLayout;
    QLabel *NetDownloadLabel;
    QLabel *NetErrLabel;
    QLabel *label_15;
    QLabel *NetUploadLabel;
    QLabel *NetIPLabel;
    QLabel *NetTCPNumLabel;
    QLabel *NetUDPDatagramLabel;
    QTableView *ProcessTable;
    QPushButton *CPU_anal_button;
    QFrame *ChartsFrame;
    QWidget *gridLayoutWidget_4;
    QGridLayout *ChartsLayout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 600);
        MainWindow->setTabletTracking(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 20, 141, 51));
        QFont font;
        font.setPointSize(13);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 20, 141, 51));
        pushButton_2->setFont(font);
        CPUInfoButton = new QCommandLinkButton(centralWidget);
        CPUInfoButton->setObjectName(QString::fromUtf8("CPUInfoButton"));
        CPUInfoButton->setGeometry(QRect(30, 150, 177, 41));
        CPUInfoButton->setFont(font);
        CPUInfoButton->setIconSize(QSize(20, 20));
        MemInfoButton = new QCommandLinkButton(centralWidget);
        MemInfoButton->setObjectName(QString::fromUtf8("MemInfoButton"));
        MemInfoButton->setGeometry(QRect(30, 300, 177, 41));
        MemInfoButton->setFont(font);
        NetworkInfoButton = new QCommandLinkButton(centralWidget);
        NetworkInfoButton->setObjectName(QString::fromUtf8("NetworkInfoButton"));
        NetworkInfoButton->setGeometry(QRect(30, 460, 177, 41));
        NetworkInfoButton->setFont(font);
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(190, 90, 41, 511));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 80, 1001, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        CPUFrame = new QFrame(centralWidget);
        CPUFrame->setObjectName(QString::fromUtf8("CPUFrame"));
        CPUFrame->setGeometry(QRect(870, 570, 21, 21));
        CPUFrame->setAutoFillBackground(false);
        CPUFrame->setFrameShape(QFrame::StyledPanel);
        CPUFrame->setFrameShadow(QFrame::Plain);
        CPUFrame->setLineWidth(1);
        gridLayoutWidget = new QWidget(CPUFrame);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 751, 461));
        CPULayout = new QGridLayout(gridLayoutWidget);
        CPULayout->setSpacing(1);
        CPULayout->setContentsMargins(11, 11, 11, 11);
        CPULayout->setObjectName(QString::fromUtf8("CPULayout"));
        CPULayout->setContentsMargins(0, 0, 0, 0);
        cpuUsageLabel = new QLabel(gridLayoutWidget);
        cpuUsageLabel->setObjectName(QString::fromUtf8("cpuUsageLabel"));
        QFont font1;
        font1.setPointSize(14);
        cpuUsageLabel->setFont(font1);
        cpuUsageLabel->setTextFormat(Qt::PlainText);
        cpuUsageLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        CPULayout->addWidget(cpuUsageLabel, 2, 0, 1, 1);

        cpuPhysicalProcessLabel = new QLabel(gridLayoutWidget);
        cpuPhysicalProcessLabel->setObjectName(QString::fromUtf8("cpuPhysicalProcessLabel"));
        cpuPhysicalProcessLabel->setFont(font1);
        cpuPhysicalProcessLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        CPULayout->addWidget(cpuPhysicalProcessLabel, 3, 1, 1, 1);

        cpuLogicProcessLabel = new QLabel(gridLayoutWidget);
        cpuLogicProcessLabel->setObjectName(QString::fromUtf8("cpuLogicProcessLabel"));
        cpuLogicProcessLabel->setFont(font1);
        cpuLogicProcessLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        CPULayout->addWidget(cpuLogicProcessLabel, 3, 0, 1, 1);

        cpuSpeedLabel = new QLabel(gridLayoutWidget);
        cpuSpeedLabel->setObjectName(QString::fromUtf8("cpuSpeedLabel"));
        cpuSpeedLabel->setFont(font1);
        cpuSpeedLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        CPULayout->addWidget(cpuSpeedLabel, 2, 1, 1, 1);

        cpuProcudureLabel = new QLabel(gridLayoutWidget);
        cpuProcudureLabel->setObjectName(QString::fromUtf8("cpuProcudureLabel"));
        cpuProcudureLabel->setFont(font1);
        cpuProcudureLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        CPULayout->addWidget(cpuProcudureLabel, 4, 0, 1, 1);

        cpuMaxProcessLabel = new QLabel(gridLayoutWidget);
        cpuMaxProcessLabel->setObjectName(QString::fromUtf8("cpuMaxProcessLabel"));
        cpuMaxProcessLabel->setFont(font1);
        cpuMaxProcessLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        CPULayout->addWidget(cpuMaxProcessLabel, 4, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        CPULayout->addWidget(label_5, 1, 0, 1, 2);

        MemFrame = new QFrame(centralWidget);
        MemFrame->setObjectName(QString::fromUtf8("MemFrame"));
        MemFrame->setGeometry(QRect(900, 570, 16, 16));
        MemFrame->setFrameShape(QFrame::StyledPanel);
        MemFrame->setFrameShadow(QFrame::Raised);
        gridLayoutWidget_2 = new QWidget(MemFrame);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(0, 0, 741, 481));
        MemLayout = new QGridLayout(gridLayoutWidget_2);
        MemLayout->setSpacing(6);
        MemLayout->setContentsMargins(11, 11, 11, 11);
        MemLayout->setObjectName(QString::fromUtf8("MemLayout"));
        MemLayout->setSizeConstraint(QLayout::SetNoConstraint);
        MemLayout->setContentsMargins(0, 0, 0, 0);
        MemBufferLabel = new QLabel(gridLayoutWidget_2);
        MemBufferLabel->setObjectName(QString::fromUtf8("MemBufferLabel"));
        MemBufferLabel->setFont(font1);
        MemBufferLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        MemLayout->addWidget(MemBufferLabel, 2, 1, 1, 1);

        MemTotalLabel = new QLabel(gridLayoutWidget_2);
        MemTotalLabel->setObjectName(QString::fromUtf8("MemTotalLabel"));
        MemTotalLabel->setFont(font1);
        MemTotalLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        MemLayout->addWidget(MemTotalLabel, 1, 0, 1, 1);

        MemCachedLabel = new QLabel(gridLayoutWidget_2);
        MemCachedLabel->setObjectName(QString::fromUtf8("MemCachedLabel"));
        MemCachedLabel->setFont(font1);
        MemCachedLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        MemLayout->addWidget(MemCachedLabel, 3, 0, 1, 1);

        MemUsageLabel = new QLabel(gridLayoutWidget_2);
        MemUsageLabel->setObjectName(QString::fromUtf8("MemUsageLabel"));
        MemUsageLabel->setFont(font1);
        MemUsageLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        MemLayout->addWidget(MemUsageLabel, 2, 0, 1, 1);

        MemSwapSizeLabel = new QLabel(gridLayoutWidget_2);
        MemSwapSizeLabel->setObjectName(QString::fromUtf8("MemSwapSizeLabel"));
        MemSwapSizeLabel->setFont(font1);
        MemSwapSizeLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        MemLayout->addWidget(MemSwapSizeLabel, 3, 1, 1, 1);

        MemFreeLabel = new QLabel(gridLayoutWidget_2);
        MemFreeLabel->setObjectName(QString::fromUtf8("MemFreeLabel"));
        MemFreeLabel->setFont(font1);
        MemFreeLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        MemLayout->addWidget(MemFreeLabel, 1, 1, 1, 1);

        MemSwapFreeLabel = new QLabel(gridLayoutWidget_2);
        MemSwapFreeLabel->setObjectName(QString::fromUtf8("MemSwapFreeLabel"));
        MemSwapFreeLabel->setFont(font1);
        MemSwapFreeLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        MemLayout->addWidget(MemSwapFreeLabel, 4, 0, 1, 1);

        MemPageSizeLabel = new QLabel(gridLayoutWidget_2);
        MemPageSizeLabel->setObjectName(QString::fromUtf8("MemPageSizeLabel"));
        MemPageSizeLabel->setFont(font1);
        MemPageSizeLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        MemLayout->addWidget(MemPageSizeLabel, 4, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        MemLayout->addWidget(label_6, 0, 0, 1, 2);

        NetFrame = new QFrame(centralWidget);
        NetFrame->setObjectName(QString::fromUtf8("NetFrame"));
        NetFrame->setGeometry(QRect(940, 570, 21, 21));
        NetFrame->setFrameShape(QFrame::StyledPanel);
        NetFrame->setFrameShadow(QFrame::Raised);
        gridLayoutWidget_3 = new QWidget(NetFrame);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(0, 0, 751, 461));
        NetLayout = new QGridLayout(gridLayoutWidget_3);
        NetLayout->setSpacing(6);
        NetLayout->setContentsMargins(11, 11, 11, 11);
        NetLayout->setObjectName(QString::fromUtf8("NetLayout"));
        NetLayout->setContentsMargins(0, 0, 0, 0);
        NetDownloadLabel = new QLabel(gridLayoutWidget_3);
        NetDownloadLabel->setObjectName(QString::fromUtf8("NetDownloadLabel"));
        NetDownloadLabel->setFont(font1);
        NetDownloadLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        NetLayout->addWidget(NetDownloadLabel, 1, 0, 1, 1);

        NetErrLabel = new QLabel(gridLayoutWidget_3);
        NetErrLabel->setObjectName(QString::fromUtf8("NetErrLabel"));
        NetErrLabel->setFont(font1);
        NetErrLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        NetLayout->addWidget(NetErrLabel, 2, 1, 1, 1);

        label_15 = new QLabel(gridLayoutWidget_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setAlignment(Qt::AlignCenter);

        NetLayout->addWidget(label_15, 0, 0, 1, 2);

        NetUploadLabel = new QLabel(gridLayoutWidget_3);
        NetUploadLabel->setObjectName(QString::fromUtf8("NetUploadLabel"));
        NetUploadLabel->setFont(font1);
        NetUploadLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        NetLayout->addWidget(NetUploadLabel, 1, 1, 1, 1);

        NetIPLabel = new QLabel(gridLayoutWidget_3);
        NetIPLabel->setObjectName(QString::fromUtf8("NetIPLabel"));
        NetIPLabel->setFont(font1);
        NetIPLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        NetLayout->addWidget(NetIPLabel, 2, 0, 1, 1);

        NetTCPNumLabel = new QLabel(gridLayoutWidget_3);
        NetTCPNumLabel->setObjectName(QString::fromUtf8("NetTCPNumLabel"));
        NetTCPNumLabel->setFont(font1);
        NetTCPNumLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        NetLayout->addWidget(NetTCPNumLabel, 3, 0, 1, 1);

        NetUDPDatagramLabel = new QLabel(gridLayoutWidget_3);
        NetUDPDatagramLabel->setObjectName(QString::fromUtf8("NetUDPDatagramLabel"));
        NetUDPDatagramLabel->setFont(font1);
        NetUDPDatagramLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        NetLayout->addWidget(NetUDPDatagramLabel, 3, 1, 1, 1);

        ProcessTable = new QTableView(centralWidget);
        ProcessTable->setObjectName(QString::fromUtf8("ProcessTable"));
        ProcessTable->setGeometry(QRect(830, 570, 21, 21));
        CPU_anal_button = new QPushButton(centralWidget);
        CPU_anal_button->setObjectName(QString::fromUtf8("CPU_anal_button"));
        CPU_anal_button->setGeometry(QRect(470, 20, 141, 51));
        CPU_anal_button->setFont(font);
        ChartsFrame = new QFrame(centralWidget);
        ChartsFrame->setObjectName(QString::fromUtf8("ChartsFrame"));
        ChartsFrame->setGeometry(QRect(800, 570, 21, 21));
        ChartsFrame->setFrameShape(QFrame::StyledPanel);
        ChartsFrame->setFrameShadow(QFrame::Raised);
        gridLayoutWidget_4 = new QWidget(ChartsFrame);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(10, 0, 981, 491));
        ChartsLayout = new QGridLayout(gridLayoutWidget_4);
        ChartsLayout->setSpacing(6);
        ChartsLayout->setContentsMargins(11, 11, 11, 11);
        ChartsLayout->setObjectName(QString::fromUtf8("ChartsLayout"));
        ChartsLayout->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\347\212\266\346\200\201", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\350\277\233\347\250\213\347\212\266\346\200\201", nullptr));
        CPUInfoButton->setText(QApplication::translate("MainWindow", "CPU\344\277\241\346\201\257", nullptr));
        MemInfoButton->setText(QApplication::translate("MainWindow", "\345\206\205\345\255\230\344\277\241\346\201\257", nullptr));
        NetworkInfoButton->setText(QApplication::translate("MainWindow", "\347\275\221\347\273\234\344\277\241\346\201\257", nullptr));
        cpuUsageLabel->setText(QApplication::translate("MainWindow", "\345\210\251\347\224\250\347\216\207:", nullptr));
        cpuPhysicalProcessLabel->setText(QApplication::translate("MainWindow", "\347\211\251\347\220\206\345\244\204\347\220\206\345\231\250\345\222\214\346\240\270\345\277\203\346\225\260\347\233\256:", nullptr));
        cpuLogicProcessLabel->setText(QApplication::translate("MainWindow", "\351\200\273\350\276\221\345\244\204\347\220\206\345\231\250\346\225\260\347\233\256:", nullptr));
        cpuSpeedLabel->setText(QApplication::translate("MainWindow", "\351\200\237\345\272\246:", nullptr));
        cpuProcudureLabel->setText(QApplication::translate("MainWindow", "\350\277\233\347\250\213\346\225\260:", nullptr));
        cpuMaxProcessLabel->setText(QApplication::translate("MainWindow", "\346\234\200\345\244\247\350\277\233\347\250\213\346\225\260:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:600;\">CPU\344\277\241\346\201\257\344\270\200\350\247\210</span></p></body></html>", nullptr));
        MemBufferLabel->setText(QApplication::translate("MainWindow", "Buffer\345\244\247\345\260\217:", nullptr));
        MemTotalLabel->setText(QApplication::translate("MainWindow", "\346\200\273\345\205\261\345\244\247\345\260\217:", nullptr));
        MemCachedLabel->setText(QApplication::translate("MainWindow", "Cached:", nullptr));
        MemUsageLabel->setText(QApplication::translate("MainWindow", "\344\275\277\347\224\250\347\216\207:", nullptr));
        MemSwapSizeLabel->setText(QApplication::translate("MainWindow", "\344\272\244\346\215\242\345\210\206\345\214\272\345\244\247\345\260\217:", nullptr));
        MemFreeLabel->setText(QApplication::translate("MainWindow", "\347\251\272\351\227\262\345\244\247\345\260\217:", nullptr));
        MemSwapFreeLabel->setText(QApplication::translate("MainWindow", "\347\251\272\351\227\262\344\272\244\346\215\242\345\244\247\345\260\217:", nullptr));
        MemPageSizeLabel->setText(QApplication::translate("MainWindow", "\351\241\265\350\241\250\347\251\272\351\227\264\345\244\247\345\260\217:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:20pt; font-weight:600;\">\345\206\205\345\255\230\344\277\241\346\201\257\344\270\200\350\247\210</span></p></body></html>", nullptr));
        NetDownloadLabel->setText(QApplication::translate("MainWindow", "\344\270\213\350\275\275\351\200\237\345\272\246:", nullptr));
        NetErrLabel->setText(QApplication::translate("MainWindow", "\351\224\231\350\257\257\346\200\273\346\225\260:", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:20pt; font-weight:600;\">\347\275\221\347\273\234\344\277\241\346\201\257\344\270\200\350\247\210</span></p></body></html>", nullptr));
        NetUploadLabel->setText(QApplication::translate("MainWindow", "\344\270\212\344\274\240\351\200\237\345\272\246:", nullptr));
        NetIPLabel->setText(QApplication::translate("MainWindow", "\346\234\254\346\234\272IP:", nullptr));
        NetTCPNumLabel->setText(QApplication::translate("MainWindow", "TCP\350\277\236\346\216\245\346\225\260:", nullptr));
        NetUDPDatagramLabel->setText(QApplication::translate("MainWindow", "UDP\346\225\260\346\215\256\346\212\245\351\200\237\345\272\246:", nullptr));
        CPU_anal_button->setText(QApplication::translate("MainWindow", "CPU\346\233\262\347\272\277\345\210\206\346\236\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
