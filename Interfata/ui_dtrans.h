/********************************************************************************
** Form generated from reading UI file 'dtrans.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DTRANS_H
#define UI_DTRANS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dTrans
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *dTrans)
    {
        if (dTrans->objectName().isEmpty())
            dTrans->setObjectName(QString::fromUtf8("dTrans"));
        dTrans->resize(493, 334);
        pushButton = new QPushButton(dTrans);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(380, 290, 91, 41));
        label = new QLabel(dTrans);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(42, 10, 411, 41));
        label->setAlignment(Qt::AlignCenter);
        textBrowser = new QTextBrowser(dTrans);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(30, 60, 431, 221));

        retranslateUi(dTrans);

        QMetaObject::connectSlotsByName(dTrans);
    } // setupUi

    void retranslateUi(QWidget *dTrans)
    {
        dTrans->setWindowTitle(QCoreApplication::translate("dTrans", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("dTrans", "Back", nullptr));
        label->setText(QCoreApplication::translate("dTrans", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dTrans: public Ui_dTrans {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DTRANS_H
