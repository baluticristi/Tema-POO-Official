/********************************************************************************
** Form generated from reading UI file 'listalocatii.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTALOCATII_H
#define UI_LISTALOCATII_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_listaLocatii
{
public:
    QPushButton *pushButton;
    QListWidget *listWidget;

    void setupUi(QWidget *listaLocatii)
    {
        if (listaLocatii->objectName().isEmpty())
            listaLocatii->setObjectName(QString::fromUtf8("listaLocatii"));
        listaLocatii->resize(738, 533);
        pushButton = new QPushButton(listaLocatii);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(560, 470, 131, 41));
        listWidget = new QListWidget(listaLocatii);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(30, 20, 671, 441));

        retranslateUi(listaLocatii);

        QMetaObject::connectSlotsByName(listaLocatii);
    } // setupUi

    void retranslateUi(QWidget *listaLocatii)
    {
        listaLocatii->setWindowTitle(QCoreApplication::translate("listaLocatii", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("listaLocatii", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class listaLocatii: public Ui_listaLocatii {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTALOCATII_H
