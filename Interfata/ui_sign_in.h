/********************************************************************************
** Form generated from reading UI file 'sign_in.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGN_IN_H
#define UI_SIGN_IN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sign_in
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLineEdit *userline;
    QLineEdit *passline;
    QLineEdit *nameline;
    QLineEdit *prenumeline;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout;
    QPushButton *creaza_Button;
    QPushButton *back_to_login;

    void setupUi(QWidget *sign_in)
    {
        if (sign_in->objectName().isEmpty())
            sign_in->setObjectName(QString::fromUtf8("sign_in"));
        sign_in->resize(557, 436);
        widget = new QWidget(sign_in);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(140, 30, 391, 261));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        userline = new QLineEdit(widget);
        userline->setObjectName(QString::fromUtf8("userline"));

        verticalLayout->addWidget(userline);

        passline = new QLineEdit(widget);
        passline->setObjectName(QString::fromUtf8("passline"));

        verticalLayout->addWidget(passline);

        nameline = new QLineEdit(widget);
        nameline->setObjectName(QString::fromUtf8("nameline"));

        verticalLayout->addWidget(nameline);

        prenumeline = new QLineEdit(widget);
        prenumeline->setObjectName(QString::fromUtf8("prenumeline"));

        verticalLayout->addWidget(prenumeline);

        widget1 = new QWidget(sign_in);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 40, 121, 241));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(widget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(widget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        widget2 = new QWidget(sign_in);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(240, 350, 291, 71));
        horizontalLayout = new QHBoxLayout(widget2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        creaza_Button = new QPushButton(widget2);
        creaza_Button->setObjectName(QString::fromUtf8("creaza_Button"));

        horizontalLayout->addWidget(creaza_Button);

        back_to_login = new QPushButton(widget2);
        back_to_login->setObjectName(QString::fromUtf8("back_to_login"));

        horizontalLayout->addWidget(back_to_login);


        retranslateUi(sign_in);

        QMetaObject::connectSlotsByName(sign_in);
    } // setupUi

    void retranslateUi(QWidget *sign_in)
    {
        sign_in->setWindowTitle(QCoreApplication::translate("sign_in", "Form", nullptr));
        label->setText(QCoreApplication::translate("sign_in", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("sign_in", "Password", nullptr));
        label_3->setText(QCoreApplication::translate("sign_in", "Nume", nullptr));
        label_4->setText(QCoreApplication::translate("sign_in", "Prenume", nullptr));
        creaza_Button->setText(QCoreApplication::translate("sign_in", "Creaza cont", nullptr));
        back_to_login->setText(QCoreApplication::translate("sign_in", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sign_in: public Ui_sign_in {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGN_IN_H
