/********************************************************************************
** Form generated from reading UI file 'addtrans.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTRANS_H
#define UI_ADDTRANS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addtrans
{
public:
    QTextEdit *textEdit;
    QPushButton *back;
    QPushButton *add;
    QLabel *label_6;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *addtrans)
    {
        if (addtrans->objectName().isEmpty())
            addtrans->setObjectName(QString::fromUtf8("addtrans"));
        addtrans->resize(799, 513);
        textEdit = new QTextEdit(addtrans);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(410, 150, 361, 251));
        back = new QPushButton(addtrans);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(670, 440, 101, 41));
        add = new QPushButton(addtrans);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(562, 440, 101, 41));
        label_6 = new QLabel(addtrans);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(420, 100, 121, 41));
        layoutWidget_2 = new QWidget(addtrans);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(90, 80, 311, 391));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(layoutWidget_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(layoutWidget_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout->addWidget(lineEdit_2);

        label = new QLabel(addtrans);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 0, 481, 81));
        label->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(addtrans);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 110, 91, 321));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);


        retranslateUi(addtrans);

        QMetaObject::connectSlotsByName(addtrans);
    } // setupUi

    void retranslateUi(QWidget *addtrans)
    {
        addtrans->setWindowTitle(QCoreApplication::translate("addtrans", "Form", nullptr));
        back->setText(QCoreApplication::translate("addtrans", "Back", nullptr));
        add->setText(QCoreApplication::translate("addtrans", "Adauga", nullptr));
        label_6->setText(QCoreApplication::translate("addtrans", "<html><head/><body><p><span style=\" font-size:12pt;\">Descriere:</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("addtrans", "<html><head/><body><p><span style=\" font-size:18pt;\">Adauga Obiective Turistice</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("addtrans", "<html><head/><body><p><span style=\" font-size:12pt;\">Nume</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("addtrans", "<html><head/><body><p><span style=\" font-size:12pt;\">Viteza</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addtrans: public Ui_addtrans {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTRANS_H
