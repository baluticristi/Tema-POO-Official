#ifndef LISTALOCATII_H
#define LISTALOCATII_H

#include <QWidget>
#include <iostream>
#include <windowsinstances.h>

using namespace std;


namespace Ui {
class listaLocatii;
}

class listaLocatii : public QWidget
{
    Q_OBJECT

public:
    explicit listaLocatii(int, QWidget *parent = nullptr);
        void adauga_lista();
    ~listaLocatii();

private slots:
    void on_pushButton_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);


private:
    Ui::listaLocatii *ui;
    int socket;
    char raspuns[4096];
    string buff;
    int count;
};

#endif // LISTALOCATII_H
