/********************************************************************************
** Form generated from reading UI file 'clientmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTMENU_H
#define UI_CLIENTMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clientmenu
{
public:
    QLabel *titlu;
    QPushButton *pushButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *locatii;
    QPushButton *transport;
    QPushButton *obiective;
    QPushButton *istoric;

    void setupUi(QWidget *clientmenu)
    {
        if (clientmenu->objectName().isEmpty())
            clientmenu->setObjectName(QString::fromUtf8("clientmenu"));
        clientmenu->resize(693, 575);
        titlu = new QLabel(clientmenu);
        titlu->setObjectName(QString::fromUtf8("titlu"));
        titlu->setGeometry(QRect(50, 0, 591, 51));
        QFont font;
        font.setPointSize(12);
        titlu->setFont(font);
        titlu->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(clientmenu);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(522, 508, 131, 51));
        widget = new QWidget(clientmenu);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 50, 591, 451));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        locatii = new QPushButton(widget);
        locatii->setObjectName(QString::fromUtf8("locatii"));

        verticalLayout->addWidget(locatii);

        transport = new QPushButton(widget);
        transport->setObjectName(QString::fromUtf8("transport"));

        verticalLayout->addWidget(transport);

        obiective = new QPushButton(widget);
        obiective->setObjectName(QString::fromUtf8("obiective"));

        verticalLayout->addWidget(obiective);

        istoric = new QPushButton(widget);
        istoric->setObjectName(QString::fromUtf8("istoric"));

        verticalLayout->addWidget(istoric);


        retranslateUi(clientmenu);

        QMetaObject::connectSlotsByName(clientmenu);
    } // setupUi

    void retranslateUi(QWidget *clientmenu)
    {
        clientmenu->setWindowTitle(QCoreApplication::translate("clientmenu", "Form", nullptr));
#if QT_CONFIG(tooltip)
        titlu->setToolTip(QCoreApplication::translate("clientmenu", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        titlu->setText(QCoreApplication::translate("clientmenu", "<html><head/><body><p><span style=\" font-size:18pt;\">TextLabel</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("clientmenu", "Disconnect", nullptr));
        locatii->setText(QCoreApplication::translate("clientmenu", "Vezi lista cu locatiile disponibile", nullptr));
        transport->setText(QCoreApplication::translate("clientmenu", "Vezi mijloacele de transport disponibile", nullptr));
        obiective->setText(QCoreApplication::translate("clientmenu", "Lista Obiectivelor turistice", nullptr));
        istoric->setText(QCoreApplication::translate("clientmenu", "Istoric", nullptr));
    } // retranslateUi

};

namespace Ui {
    class clientmenu: public Ui_clientmenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTMENU_H
