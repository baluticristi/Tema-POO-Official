/********************************************************************************
** Form generated from reading UI file 'dobiective.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOBIECTIVE_H
#define UI_DOBIECTIVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dObiective
{
public:
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QWidget *dObiective)
    {
        if (dObiective->objectName().isEmpty())
            dObiective->setObjectName(QString::fromUtf8("dObiective"));
        dObiective->resize(487, 346);
        textBrowser = new QTextBrowser(dObiective);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(30, 70, 431, 221));
        pushButton = new QPushButton(dObiective);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(380, 300, 91, 41));
        label = new QLabel(dObiective);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(42, 20, 411, 41));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(dObiective);

        QMetaObject::connectSlotsByName(dObiective);
    } // setupUi

    void retranslateUi(QWidget *dObiective)
    {
        dObiective->setWindowTitle(QCoreApplication::translate("dObiective", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("dObiective", "Back", nullptr));
        label->setText(QCoreApplication::translate("dObiective", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dObiective: public Ui_dObiective {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOBIECTIVE_H
