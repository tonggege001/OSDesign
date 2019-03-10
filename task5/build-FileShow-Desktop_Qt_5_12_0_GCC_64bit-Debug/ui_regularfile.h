/********************************************************************************
** Form generated from reading UI file 'regularfile.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGULARFILE_H
#define UI_REGULARFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_regularfile
{
public:
    QLabel *label;
    QLabel *filename;

    void setupUi(QWidget *regularfile)
    {
        if (regularfile->objectName().isEmpty())
            regularfile->setObjectName(QString::fromUtf8("regularfile"));
        regularfile->resize(100, 120);
        regularfile->setContextMenuPolicy(Qt::ActionsContextMenu);
        label = new QLabel(regularfile);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 100, 100));
        label->setPixmap(QPixmap(QString::fromUtf8("../image/regularfile.jpeg")));
        label->setScaledContents(true);
        filename = new QLabel(regularfile);
        filename->setObjectName(QString::fromUtf8("filename"));
        filename->setGeometry(QRect(0, 100, 101, 20));
        filename->setAlignment(Qt::AlignCenter);

        retranslateUi(regularfile);

        QMetaObject::connectSlotsByName(regularfile);
    } // setupUi

    void retranslateUi(QWidget *regularfile)
    {
        regularfile->setWindowTitle(QApplication::translate("regularfile", "Form", nullptr));
        label->setText(QString());
        filename->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class regularfile: public Ui_regularfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGULARFILE_H
