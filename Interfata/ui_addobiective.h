/********************************************************************************
** Form generated from reading UI file 'addobiective.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDOBIECTIVE_H
#define UI_ADDOBIECTIVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addobiective
{
public:
    QTextEdit *textEdit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *add;
    QPushButton *back;
    QLabel *label;
    QLabel *label_6;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;

    void setupUi(QWidget *addobiective)
    {
        if (addobiective->objectName().isEmpty())
            addobiective->setObjectName(QString::fromUtf8("addobiective"));
        addobiective->resize(824, 523);
        textEdit = new QTextEdit(addobiective);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(430, 150, 361, 251));
        layoutWidget = new QWidget(addobiective);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 110, 91, 321));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        add = new QPushButton(addobiective);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(582, 440, 101, 41));
        back = new QPushButton(addobiective);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(690, 440, 101, 41));
        label = new QLabel(addobiective);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 0, 481, 81));
        label->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(addobiective);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(440, 100, 121, 41));
        layoutWidget_2 = new QWidget(addobiective);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(110, 80, 311, 391));
        verticalLayout = new QVBoxLayout(layoutWidget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(layoutWidget_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(layoutWidget_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout->addWidget(lineEdit_2);


        retranslateUi(addobiective);

        QMetaObject::connectSlotsByName(addobiective);
    } // setupUi

    void retranslateUi(QWidget *addobiective)
    {
        addobiective->setWindowTitle(QCoreApplication::translate("addobiective", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("addobiective", "<html><head/><body><p><span style=\" font-size:12pt;\">Nume</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("addobiective", "<html><head/><body><p><span style=\" font-size:12pt;\">Judet</span></p></body></html>", nullptr));
        add->setText(QCoreApplication::translate("addobiective", "Adauga", nullptr));
        back->setText(QCoreApplication::translate("addobiective", "Back", nullptr));
        label->setText(QCoreApplication::translate("addobiective", "<html><head/><body><p><span style=\" font-size:18pt;\">Adauga Obiective Turistice</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("addobiective", "<html><head/><body><p><span style=\" font-size:12pt;\">Descriere:</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addobiective: public Ui_addobiective {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDOBIECTIVE_H
