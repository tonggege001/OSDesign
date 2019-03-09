/********************************************************************************
** Form generated from reading UI file 'directory.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIRECTORY_H
#define UI_DIRECTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_directory
{
public:
    QLabel *label;
    QLabel *filename;

    void setupUi(QWidget *directory)
    {
        if (directory->objectName().isEmpty())
            directory->setObjectName(QString::fromUtf8("directory"));
        directory->resize(100, 120);
        label = new QLabel(directory);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 100, 100));
        label->setPixmap(QPixmap(QString::fromUtf8("../image/directory.jpg")));
        label->setScaledContents(true);
        filename = new QLabel(directory);
        filename->setObjectName(QString::fromUtf8("filename"));
        filename->setGeometry(QRect(0, 100, 101, 20));
        filename->setAlignment(Qt::AlignCenter);

        retranslateUi(directory);

        QMetaObject::connectSlotsByName(directory);
    } // setupUi

    void retranslateUi(QWidget *directory)
    {
        directory->setWindowTitle(QApplication::translate("directory", "Form", nullptr));
        label->setText(QString());
        filename->setText(QApplication::translate("directory", "/", nullptr));
    } // retranslateUi

};

namespace Ui {
    class directory: public Ui_directory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIRECTORY_H
