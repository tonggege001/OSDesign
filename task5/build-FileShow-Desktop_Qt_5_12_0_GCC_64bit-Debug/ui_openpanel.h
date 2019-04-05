/********************************************************************************
** Form generated from reading UI file 'openpanel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENPANEL_H
#define UI_OPENPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_OpenPanel
{
public:
    QDialogButtonBox *buttonBox;
    QTextEdit *textEdit;
    QLabel *label;
    QLabel *filename_label;

    void setupUi(QDialog *OpenPanel)
    {
        if (OpenPanel->objectName().isEmpty())
            OpenPanel->setObjectName(QString::fromUtf8("OpenPanel"));
        OpenPanel->resize(521, 363);
        buttonBox = new QDialogButtonBox(OpenPanel);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(140, 310, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        textEdit = new QTextEdit(OpenPanel);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 50, 491, 251));
        label = new QLabel(OpenPanel);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 10, 71, 21));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        filename_label = new QLabel(OpenPanel);
        filename_label->setObjectName(QString::fromUtf8("filename_label"));
        filename_label->setGeometry(QRect(180, 10, 311, 21));
        filename_label->setFont(font);

        retranslateUi(OpenPanel);
        QObject::connect(buttonBox, SIGNAL(accepted()), OpenPanel, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OpenPanel, SLOT(reject()));

        QMetaObject::connectSlotsByName(OpenPanel);
    } // setupUi

    void retranslateUi(QDialog *OpenPanel)
    {
        OpenPanel->setWindowTitle(QApplication::translate("OpenPanel", "Dialog", nullptr));
        label->setText(QApplication::translate("OpenPanel", "\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        filename_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OpenPanel: public Ui_OpenPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENPANEL_H
