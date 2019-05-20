#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "array.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QString begin_l = "100";
    QString begin_e = "0";
    QString tmp2;                                                       //to show counters
    int step_counter = 0;
    int radio = 0;
    bool tmp = false;
    int *A;
    int key;
    int size;                                                        //size of the array
    QPalette *palette = new QPalette();
    QPalette *palette2 = new QPalette();
/////////////////////////////////////////////////


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    void output(int index);
    int Binary_search(int &counter, int parametr);
    int Odnorodniy_Binary_search(int &counter, int parametr);
    int Sharr_search(int &counter, int parametr);


private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
