#ifndef CLIENTMENU_H
#define CLIENTMENU_H

#include <QWidget>
#include <QListWidget>
#include <iostream>
#include <windowsinstances.h>

using namespace std;

namespace Ui {
class clientmenu;
}

class clientmenu : public QWidget
{
    Q_OBJECT

public:
    explicit clientmenu(int,QWidget *parent = nullptr);
    ~clientmenu();
    void nume_prenume(QString n, QString p);
private slots:
    void on_pushButton_clicked();

    void on_locatii_clicked();

    void on_transport_clicked();

    void on_istoric_clicked();

    void on_obiective_clicked();

private:
    Ui::clientmenu *ui;
    int socket;
    QString nume;
    QString prenume;
};

#endif // CLIENTMENU_H
