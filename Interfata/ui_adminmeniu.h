/********************************************************************************
** Form generated from reading UI file 'adminmeniu.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINMENIU_H
#define UI_ADMINMENIU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminmeniu
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *addObiectiv;
    QPushButton *delObiectiv;
    QPushButton *addTransport;
    QPushButton *pushButton_4;
    QPushButton *addCazare;
    QPushButton *delCazare;
    QPushButton *pushButton;

    void setupUi(QWidget *adminmeniu)
    {
        if (adminmeniu->objectName().isEmpty())
            adminmeniu->setObjectName(QString::fromUtf8("adminmeniu"));
        adminmeniu->resize(624, 436);
        layoutWidget = new QWidget(adminmeniu);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 10, 521, 361));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        addObiectiv = new QPushButton(layoutWidget);
        addObiectiv->setObjectName(QString::fromUtf8("addObiectiv"));

        verticalLayout->addWidget(addObiectiv);

        delObiectiv = new QPushButton(layoutWidget);
        delObiectiv->setObjectName(QString::fromUtf8("delObiectiv"));

        verticalLayout->addWidget(delObiectiv);

        addTransport = new QPushButton(layoutWidget);
        addTransport->setObjectName(QString::fromUtf8("addTransport"));

        verticalLayout->addWidget(addTransport);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        addCazare = new QPushButton(layoutWidget);
        addCazare->setObjectName(QString::fromUtf8("addCazare"));

        verticalLayout->addWidget(addCazare);

        delCazare = new QPushButton(layoutWidget);
        delCazare->setObjectName(QString::fromUtf8("delCazare"));

        verticalLayout->addWidget(delCazare);

        pushButton = new QPushButton(adminmeniu);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(490, 380, 121, 41));

        retranslateUi(adminmeniu);

        QMetaObject::connectSlotsByName(adminmeniu);
    } // setupUi

    void retranslateUi(QWidget *adminmeniu)
    {
        adminmeniu->setWindowTitle(QCoreApplication::translate("adminmeniu", "Form", nullptr));
        addObiectiv->setText(QCoreApplication::translate("adminmeniu", "Add Obiective Turistice", nullptr));
        delObiectiv->setText(QCoreApplication::translate("adminmeniu", "Del Obiective Turistice", nullptr));
        addTransport->setText(QCoreApplication::translate("adminmeniu", "Add Mijloace Transport", nullptr));
        pushButton_4->setText(QCoreApplication::translate("adminmeniu", "Del Mijloace Transport", nullptr));
        addCazare->setText(QCoreApplication::translate("adminmeniu", "Add Cazare", nullptr));
        delCazare->setText(QCoreApplication::translate("adminmeniu", "Del Cazare", nullptr));
        pushButton->setText(QCoreApplication::translate("adminmeniu", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminmeniu: public Ui_adminmeniu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINMENIU_H
