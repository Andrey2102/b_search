#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QTextBrowser>
#include <cmath>
#include "array.h"

void MainWindow::output(int index){
    QString data;
    data+= "ARRAY";
    for( int i = 0, k = 0; i < size; i++, k++){
        if (k % 10 == 0){
            data+= '\n';
            data+= '\n';
        }
        if(i == index){
        data+= "[";
        data+= QString::number(A[i]);
        data+= "]";
        }
        else{
            data+= QString::number(A[i]);
        }
        switch ((QString::number(A[i])).length()) {
        case 1:
           data+= "                      ";
            break;
        case 2:
           data+= "                    ";
            break;
        case 3:
           data+= "                 ";
            break;
        case 4:
           data+= "              ";
            break;
        case 5:
           data+= "           ";
            break;
        case 6:
           data+= "        ";
            break;
        case 7:
           data+= "     ";
            break;
        case 8:
           data+= "  ";
            break;
        default:
            data+= '\n';
            break;
        }
    }
    ui->textBrowser->clear();
    ui->textBrowser->insertPlainText(data);

}


/////////////////////////////////////////////////////////////////////////////////////

int MainWindow::Binary_search(int &counter, int parametr)
{
    int left = 0;
    int right = size;
    int midd = 0;
    while (1)
    {
        midd = (left + right) / 2;
        counter++;
        if(parametr == 1){

            output(midd);
            ui->label_10->clear();
            ui->label_10->setText(QString::number(midd));
            ui->label_11->clear();
            ui->label_11->setText(QString::number(A[midd]));

        }
        if (key < A[midd])
            right = midd - 1;
        else if (key > A[midd])
            left = midd + 1;
        else
            return midd;

        if (left > right)
            return -1;
    }
}

/////////////////////////////////////////////////////////////////////////////////////

int MainWindow::Odnorodniy_Binary_search(int &counter, int parametr)
{
    int index, delta = size / 2;
    index = delta;
    while (true)
    {
        counter++;
        delta= delta/2;
        if (A[index] == key)
        {
            break;
        }
        if (A[index] > key)
        {
            index = index - delta;
        }
        if (A[index] < key)
        {
            index = index + delta;
        }
        if (delta == 0)
        {
            break;
        }
    }
    if(A[index] != key){
        return -1;
    }
    return index;
}

/////////////////////////////////////////////////////////////////////////////////////

int MainWindow::Sharr_search(int &counter, int parametr){
    int n = size;
    int k = log2(n);
        int index = pow(2, k);
        int comparison = 1;
        if (key == A[index])return index;
        if (key < A[index])
        {
            for (int i = 1; i <= k; i++)
            {
                comparison++;
                counter++;
                int del = pow(2, k - i);
                if (key == A[index])
                {
                    break;
                }
                if (key < A[index]){
                    index = index - del;
                }
                else{
                    index = index + del;
                }
                if (key == A[index])
                {
                    break;
                }
                if (i == k)
                {
                    return -1;
                }
            }
        }
        if (key > A[index])
        {
            int l = log2(n - pow(2, k)) + 1;
            index = n + 1 - pow(2, l);
            if (key > A[index])
            {
                for (int j = 1; j <= l; j++)
                {
                    counter++;
                    comparison++;
                    int del = pow(2, l - j);
                    if (key == A[index])
                    {
                        break;
                    }
                    if (key < A[index]){
                        index = index - del;
                    }
                    else{
                        index = index + del;
                    }
                    if (key == A[index])
                    {
                        break;
                    }
                    if (j == l)
                    {
                        return -1;
                    }
                }
            }
        }
        return index;
}


/////////////////////////////////////////////////////////////////////////////////////


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText(begin_l);
    ui->lineEdit_2->setText(begin_e);

/////////////////////////////////////////////////////////////////


    palette->setColor(QPalette::Base,Qt::lightGray);
    palette->setColor(QPalette::Text,Qt::gray);
    palette2->setColor(QPalette::Base,Qt::white);
    palette2->setColor(QPalette::Text,Qt::black);


    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_2->setPalette(*palette);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->label_9->setText(" - ");
    ui->label_10->setText(" - ");
    ui->label_11->setText(" - ");
    ui->label_12->setText(" - ");
    ui->label_13->setText(" - ");


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_4_clicked()
{
    close();
}

/////////////////////////////////////////////////////////////////////////////////////

void MainWindow::on_pushButton_clicked()
{
/////////////////////////////////

    if(radio == 0){
        return;
    }


    ui->radioButton->setEnabled(false);
    ui->radioButton_2->setEnabled(false);
    ui->radioButton_3->setEnabled(false);
    ui->pushButton->setEnabled(false);


/////////////////////////////////
    QString inp_s = ui->lineEdit->text();                                 //if we didn`t write the size, it will be 100 (Default value)

    if (inp_s.isEmpty() || inp_s.toInt() < 0){ui->lineEdit->setText(begin_l);}
    size = inp_s.toInt();

    ui->lineEdit->setReadOnly(true);
    ui->lineEdit->setPalette(*palette);

//////////////////////////////////////////////////////////////////

    ARRAY arr(size);
    A = new int [size];
    arr.getArr(A);

//////////////////////////////////////////////////////////////////
    QString data;
    data+= "ARRAY:";
    for (int i = 0, k = 0; i < size; i++, k++){
        if (k % 10 == 0){
            data+= '\n';
            data+= '\n';
        }
        data+= QString::number(A[i]);
        switch ((QString::number(A[i])).length()) {
        case 1:
           data+= "                      ";
            break;
        case 2:
           data+= "                    ";
            break;
        case 3:
           data+= "                 ";
            break;
        case 4:
           data+= "              ";
            break;
        case 5:
           data+= "           ";
            break;
        case 6:
           data+= "        ";
            break;
        case 7:
           data+= "     ";
            break;
        case 8:
           data+= "  ";
            break;
        default:
            data+= '\n';
            break;
        }

    }
    ui->textBrowser->insertPlainText(data);
    ui->lineEdit_2->setReadOnly(false);
    ui->lineEdit_2->setPalette(*palette2);
    ui->pushButton_5->setEnabled(true);

}


/////////////////////////////////////////////////////////////////////////////////////


void MainWindow::on_pushButton_2_clicked()
{
    ui->pushButton_3->setEnabled(false);
    int res;
    switch (radio) {
    case 1:
        res = Binary_search(step_counter, 1);
        break;
    case 2:
        res = Odnorodniy_Binary_search(step_counter, 1);
        break;
    case 3:
        res = Sharr_search(step_counter, 1);
        break;
    default:
        break;
    }
    if(res == -1){
        ui->label_9->clear();
        ui->label_9->setText(QString::number(step_counter));
        ui->label_10->clear();
        ui->label_10->setText("Non");
        ui->label_11->clear();
        ui->label_11->setText("Non");
        ui->label_12->clear();
        ui->label_12->setText("Non");
        ui->label_13->clear();
        ui->label_13->setText("Non");
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
    }
    else{
        ui->label_9->clear();
        ui->label_9->setText(QString::number(step_counter));
        ui->label_10->clear();
        ui->label_10->setText("Non");
        ui->label_11->clear();
        ui->label_11->setText("Non");
        ui->label_12->clear();
        ui->label_12->setText(QString::number(res));
        ui->label_13->clear();
        ui->label_13->setText(QString::number(A[res]));
        ui->pushButton_2->setEnabled(false);
    }
}


/////////////////////////////////////////////////////////////////////////////////////



void MainWindow::on_pushButton_3_clicked()
{
    int res;
    switch (radio) {
    case 1:

        res = Binary_search(step_counter, 2);
        break;
    case 2:
        res = Odnorodniy_Binary_search(step_counter, 2);
        break;
    case 3:
        res = Sharr_search(step_counter, 2);
        break;
    default:
        break;
    }
    if(res == -1){
        ui->label_9->clear();
        ui->label_9->setText(QString::number(step_counter));
        ui->label_10->clear();
        ui->label_10->setText("Non");
        ui->label_11->clear();
        ui->label_11->setText("Non");
        ui->label_12->clear();
        ui->label_12->setText("Non");
        ui->label_13->clear();
        ui->label_13->setText("Non");
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
    }
    else{
        ui->label_9->clear();
        ui->label_9->setText(QString::number(step_counter));
        ui->label_10->clear();
        ui->label_10->setText("Non");
        ui->label_11->clear();
        ui->label_11->setText("Non");
        ui->label_12->clear();
        ui->label_12->setText(QString::number(res));
        ui->label_13->clear();
        ui->label_13->setText(QString::number(A[res]));
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
    }
}

/////////////////////////////////////////////////////////////////////////////////////

void MainWindow::on_radioButton_3_clicked()
{
    radio = 1;
}

void MainWindow::on_radioButton_2_clicked()
{
    radio = 2;
}

void MainWindow::on_radioButton_clicked()
{
    radio = 3;
}

/////////////////////////////////////////////////////////////////////////////////////

void MainWindow::on_pushButton_5_clicked()
{
    QString inp_key = ui->lineEdit_2->text();
    if (inp_key.isEmpty() || inp_key.toInt() < 0){ui->lineEdit_2->setText(begin_e);}
    key = inp_key.toInt();
    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_2->setPalette(*palette);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_2->setEnabled(true);

}
/////////////////////////////////////////////////////////////////////////////////////
