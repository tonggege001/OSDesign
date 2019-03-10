/********************************************************************************
** Form generated from reading UI file 'createdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEDIALOG_H
#define UI_CREATEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;

    void setupUi(QDialog *CreateDialog)
    {
        if (CreateDialog->objectName().isEmpty())
            CreateDialog->setObjectName(QString::fromUtf8("CreateDialog"));
        CreateDialog->resize(400, 255);
        CreateDialog->setFocusPolicy(Qt::StrongFocus);
        buttonBox = new QDialogButtonBox(CreateDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 210, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(CreateDialog);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(-1, -1, 411, 201));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(50);
        formLayout->setVerticalSpacing(50);
        formLayout->setContentsMargins(30, 50, 30, 30);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(formLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEdit_2 = new QLineEdit(formLayoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);


        retranslateUi(CreateDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreateDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreateDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateDialog)
    {
        CreateDialog->setWindowTitle(QApplication::translate("CreateDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("CreateDialog", "\346\226\207\344\273\266\345\220\215", nullptr));
        label_2->setText(QApplication::translate("CreateDialog", "\346\211\200\346\234\211\350\200\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateDialog: public Ui_CreateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEDIALOG_H
