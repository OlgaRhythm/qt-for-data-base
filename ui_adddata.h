/********************************************************************************
** Form generated from reading UI file 'adddata.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDATA_H
#define UI_ADDDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddData
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *label_5;
    QLineEdit *lineEdit_6;
    QLabel *label_6;
    QLabel *label;

    void setupUi(QDialog *AddData)
    {
        if (AddData->objectName().isEmpty())
            AddData->setObjectName("AddData");
        AddData->resize(400, 300);
        buttonBox = new QDialogButtonBox(AddData);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(220, 260, 156, 24));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(AddData);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(30, 50, 331, 191));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(formLayoutWidget);
        lineEdit->setObjectName("lineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEdit_2 = new QLineEdit(formLayoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEdit_3 = new QLineEdit(formLayoutWidget);
        lineEdit_3->setObjectName("lineEdit_3");

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        lineEdit_4 = new QLineEdit(formLayoutWidget);
        lineEdit_4->setObjectName("lineEdit_4");

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_4);

        lineEdit_5 = new QLineEdit(formLayoutWidget);
        lineEdit_5->setObjectName("lineEdit_5");

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_5);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        lineEdit_6 = new QLineEdit(formLayoutWidget);
        lineEdit_6->setObjectName("lineEdit_6");

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_6);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);


        retranslateUi(AddData);

        QMetaObject::connectSlotsByName(AddData);
    } // setupUi

    void retranslateUi(QDialog *AddData)
    {
        AddData->setWindowTitle(QCoreApplication::translate("AddData", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("AddData", "\320\237\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\270\321\202\320\265\320\273\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("AddData", "\320\246\320\262\320\265\321\202", nullptr));
        label_4->setText(QCoreApplication::translate("AddData", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\264\320\270\321\201\320\277\320\273\320\265\321\217", nullptr));
        label_5->setText(QCoreApplication::translate("AddData", "\320\201\320\274\320\272\320\276\321\201\321\202\321\214 \320\261\320\260\321\202\320\260\321\200\320\265\320\270", nullptr));
        label_6->setText(QCoreApplication::translate("AddData", "\320\223\320\276\320\264 \320\262\321\213\320\277\321\203\321\201\320\272\320\260", nullptr));
        label->setText(QCoreApplication::translate("AddData", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddData: public Ui_AddData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDATA_H
