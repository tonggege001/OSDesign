/********************************************************************************
** Form generated from reading UI file 'tggdirectory.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TGGDIRECTORY_H
#define UI_TGGDIRECTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TGGdirectory
{
public:
    QLabel *label;
    QLabel *filename;

    void setupUi(QWidget *TGGdirectory)
    {
        if (TGGdirectory->objectName().isEmpty())
            TGGdirectory->setObjectName(QString::fromUtf8("TGGdirectory"));
        TGGdirectory->resize(100, 120);
        label = new QLabel(TGGdirectory);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 100, 100));
        label->setPixmap(QPixmap(QString::fromUtf8("../image/directory.jpg")));
        label->setScaledContents(true);
        filename = new QLabel(TGGdirectory);
        filename->setObjectName(QString::fromUtf8("filename"));
        filename->setGeometry(QRect(0, 100, 101, 17));
        filename->setAlignment(Qt::AlignCenter);

        retranslateUi(TGGdirectory);

        QMetaObject::connectSlotsByName(TGGdirectory);
    } // setupUi

    void retranslateUi(QWidget *TGGdirectory)
    {
        TGGdirectory->setWindowTitle(QApplication::translate("TGGdirectory", "Form", nullptr));
        label->setText(QString());
        filename->setText(QApplication::translate("TGGdirectory", "/", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TGGdirectory: public Ui_TGGdirectory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TGGDIRECTORY_H
