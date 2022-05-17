/********************************************************************************
** Form generated from reading UI file 'listatransport.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTATRANSPORT_H
#define UI_LISTATRANSPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_listatransport
{
public:
    QListWidget *listWidget;
    QPushButton *pushButton;

    void setupUi(QWidget *listatransport)
    {
        if (listatransport->objectName().isEmpty())
            listatransport->setObjectName(QString::fromUtf8("listatransport"));
        listatransport->resize(664, 474);
        listWidget = new QListWidget(listatransport);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(40, 20, 591, 391));
        pushButton = new QPushButton(listatransport);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(540, 420, 101, 31));

        retranslateUi(listatransport);

        QMetaObject::connectSlotsByName(listatransport);
    } // setupUi

    void retranslateUi(QWidget *listatransport)
    {
        listatransport->setWindowTitle(QCoreApplication::translate("listatransport", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("listatransport", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class listatransport: public Ui_listatransport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTATRANSPORT_H
