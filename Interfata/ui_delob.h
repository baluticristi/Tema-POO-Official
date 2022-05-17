/********************************************************************************
** Form generated from reading UI file 'delob.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELOB_H
#define UI_DELOB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_delOb
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;

    void setupUi(QWidget *delOb)
    {
        if (delOb->objectName().isEmpty())
            delOb->setObjectName(QString::fromUtf8("delOb"));
        delOb->resize(431, 321);
        pushButton = new QPushButton(delOb);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 240, 83, 29));
        pushButton_2 = new QPushButton(delOb);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(330, 280, 83, 29));
        label = new QLabel(delOb);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 130, 91, 41));
        lineEdit = new QLineEdit(delOb);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(120, 140, 281, 41));
        label_2 = new QLabel(delOb);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 20, 391, 31));
        QFont font;
        font.setPointSize(12);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(delOb);

        QMetaObject::connectSlotsByName(delOb);
    } // setupUi

    void retranslateUi(QWidget *delOb)
    {
        delOb->setWindowTitle(QCoreApplication::translate("delOb", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("delOb", "Delete", nullptr));
        pushButton_2->setText(QCoreApplication::translate("delOb", "Back", nullptr));
        label->setText(QCoreApplication::translate("delOb", " Denumire:", nullptr));
        label_2->setText(QCoreApplication::translate("delOb", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class delOb: public Ui_delOb {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELOB_H
