/********************************************************************************
** Form generated from reading UI file 'locatiemenu.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCATIEMENU_H
#define UI_LOCATIEMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_locatiemenu
{
public:
    QLabel *LocName;
    QTextBrowser *desc;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QComboBox *comboBox;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QDateEdit *dateEdit_3;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_2;

    void setupUi(QWidget *locatiemenu)
    {
        if (locatiemenu->objectName().isEmpty())
            locatiemenu->setObjectName(QString::fromUtf8("locatiemenu"));
        locatiemenu->resize(820, 553);
        LocName = new QLabel(locatiemenu);
        LocName->setObjectName(QString::fromUtf8("LocName"));
        LocName->setGeometry(QRect(30, 30, 451, 61));
        QFont font;
        font.setPointSize(22);
        LocName->setFont(font);
        LocName->setAlignment(Qt::AlignCenter);
        desc = new QTextBrowser(locatiemenu);
        desc->setObjectName(QString::fromUtf8("desc"));
        desc->setGeometry(QRect(30, 110, 401, 411));
        layoutWidget = new QWidget(locatiemenu);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(450, 170, 351, 71));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        layoutWidget1 = new QWidget(locatiemenu);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(520, 290, 251, 81));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        dateEdit_3 = new QDateEdit(layoutWidget1);
        dateEdit_3->setObjectName(QString::fromUtf8("dateEdit_3"));

        horizontalLayout_2->addWidget(dateEdit_3);

        layoutWidget2 = new QWidget(locatiemenu);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(450, 480, 361, 61));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(layoutWidget2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);

        pushButton = new QPushButton(layoutWidget2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        layoutWidget3 = new QWidget(locatiemenu);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(530, 20, 251, 131));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(layoutWidget3);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        dateEdit = new QDateEdit(layoutWidget3);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        verticalLayout_2->addWidget(dateEdit);

        dateEdit_2 = new QDateEdit(layoutWidget3);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));

        verticalLayout_2->addWidget(dateEdit_2);


        horizontalLayout_4->addLayout(verticalLayout_2);


        retranslateUi(locatiemenu);

        QMetaObject::connectSlotsByName(locatiemenu);
    } // setupUi

    void retranslateUi(QWidget *locatiemenu)
    {
        locatiemenu->setWindowTitle(QCoreApplication::translate("locatiemenu", "Form", nullptr));
        LocName->setText(QCoreApplication::translate("locatiemenu", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("locatiemenu", "Alege transport", nullptr));
        label_4->setText(QCoreApplication::translate("locatiemenu", "Data transport:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("locatiemenu", "Rezerva", nullptr));
        pushButton->setText(QCoreApplication::translate("locatiemenu", "Back", nullptr));
        label->setText(QCoreApplication::translate("locatiemenu", "Data sosire", nullptr));
        label_2->setText(QCoreApplication::translate("locatiemenu", "Data plecare", nullptr));
    } // retranslateUi

};

namespace Ui {
    class locatiemenu: public Ui_locatiemenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCATIEMENU_H
