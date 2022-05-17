/********************************************************************************
** Form generated from reading UI file 'oblictiveturistice.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBLICTIVETURISTICE_H
#define UI_OBLICTIVETURISTICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_oblictiveTuristice
{
public:
    QListWidget *listWidget;
    QPushButton *pushButton;

    void setupUi(QWidget *oblictiveTuristice)
    {
        if (oblictiveTuristice->objectName().isEmpty())
            oblictiveTuristice->setObjectName(QString::fromUtf8("oblictiveTuristice"));
        oblictiveTuristice->resize(687, 425);
        listWidget = new QListWidget(oblictiveTuristice);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(30, 20, 621, 341));
        pushButton = new QPushButton(oblictiveTuristice);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(550, 370, 111, 41));

        retranslateUi(oblictiveTuristice);

        QMetaObject::connectSlotsByName(oblictiveTuristice);
    } // setupUi

    void retranslateUi(QWidget *oblictiveTuristice)
    {
        oblictiveTuristice->setWindowTitle(QCoreApplication::translate("oblictiveTuristice", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("oblictiveTuristice", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class oblictiveTuristice: public Ui_oblictiveTuristice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBLICTIVETURISTICE_H
