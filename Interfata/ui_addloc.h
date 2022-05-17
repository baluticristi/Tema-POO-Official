/********************************************************************************
** Form generated from reading UI file 'addloc.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDLOC_H
#define UI_ADDLOC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addloc
{
public:
    QPushButton *back;
    QPushButton *add;
    QLabel *label;
    QTextEdit *textEdit;
    QLabel *label_6;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QWidget *addloc)
    {
        if (addloc->objectName().isEmpty())
            addloc->setObjectName(QString::fromUtf8("addloc"));
        addloc->resize(874, 517);
        back = new QPushButton(addloc);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(740, 450, 101, 41));
        add = new QPushButton(addloc);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(632, 450, 101, 41));
        label = new QLabel(addloc);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 10, 331, 51));
        label->setAlignment(Qt::AlignCenter);
        textEdit = new QTextEdit(addloc);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(480, 160, 361, 251));
        label_6 = new QLabel(addloc);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(490, 110, 121, 41));
        widget = new QWidget(addloc);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(140, 90, 311, 391));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        verticalLayout->addWidget(lineEdit_4);

        widget1 = new QWidget(addloc);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(50, 120, 91, 321));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(widget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(widget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(widget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);


        retranslateUi(addloc);

        QMetaObject::connectSlotsByName(addloc);
    } // setupUi

    void retranslateUi(QWidget *addloc)
    {
        addloc->setWindowTitle(QCoreApplication::translate("addloc", "Form", nullptr));
        back->setText(QCoreApplication::translate("addloc", "Back", nullptr));
        add->setText(QCoreApplication::translate("addloc", "Adauga", nullptr));
        label->setText(QCoreApplication::translate("addloc", "<html><head/><body><p><span style=\" font-size:18pt;\">Adauga Locatii</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("addloc", "<html><head/><body><p><span style=\" font-size:12pt;\">Descriere:</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("addloc", "<html><head/><body><p><span style=\" font-size:12pt;\">Nume</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("addloc", "<html><head/><body><p><span style=\" font-size:12pt;\">Judet</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("addloc", "<html><head/><body><p><span style=\" font-size:12pt;\">Camere</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("addloc", "<html><head/><body><p><span style=\" font-size:12pt;\">Stele</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addloc: public Ui_addloc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDLOC_H
