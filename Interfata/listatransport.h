#ifndef LISTATRANSPORT_H
#define LISTATRANSPORT_H

#include <QWidget>
#include <iostream>
#include <windowsinstances.h>

using namespace std;


namespace Ui {
class listatransport;
}

class listatransport : public QWidget
{
    Q_OBJECT

public:
    explicit listatransport(int,QWidget *parent = nullptr);
    ~listatransport();

private slots:
    void on_pushButton_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::listatransport *ui;
    int socket;
    char raspuns[4096];
    string buff;
    void adauga_lista();
};

#endif // LISTATRANSPORT_H
