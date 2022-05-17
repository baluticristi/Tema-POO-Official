#ifndef OBLICTIVETURISTICE_H
#define OBLICTIVETURISTICE_H

#include <QWidget>
#include <iostream>
#include"windowsinstances.h"
#include <winsock.h>

using namespace std;

namespace Ui {
class oblictiveTuristice;
}

class oblictiveTuristice : public QWidget
{
    Q_OBJECT

public:
    explicit oblictiveTuristice(int,QWidget *parent = nullptr);
    ~oblictiveTuristice();

private slots:
    void on_pushButton_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::oblictiveTuristice *ui;
    int socket;
    string buff;
    char raspuns[255];
    void adauga_lista();
    int count;
};

#endif // OBLICTIVETURISTICE_H
