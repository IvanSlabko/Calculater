#include "mainwindow.h"
#include "calc.h"
#include "ui_mainwindow.h"

char *variable;
int i;
char *outDispl;
int n;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    variable = (char*)malloc(255*sizeof(char));
    outDispl = (char*)malloc(255*sizeof(char));
    variable[254] = '\0';
    outDispl[254] = '\0';
    for (i = 0; i<255; i++) {
        variable[i] = ' ';
        outDispl[i] = ' ';
    }

    for (i = 0; i< 5; i++){
        variable[i] = '0';
    }

    n = 0;
    i = 5;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    variable[i] = '1';
    i++;
    outDispl[n] = '1';
    n++;

    ui->label->setText(outDispl);
}

void MainWindow::on_pushButton_2_clicked()
{
    variable[i] = '2';
    i++;
    outDispl[n] = '2';
    n++;

    ui->label->setText(outDispl);
}

void MainWindow::on_pushButton_3_clicked()
{
    variable[i] = '+';
    i++;
    outDispl[n] = '+';
    n++;

    ui->label->setText(outDispl);
}

void MainWindow::on_pushButton_4_clicked()
{
    calcPars(variable);
    ui->label->setText(variable);
    free(variable);
    free(outDispl);
    variable = (char*)malloc(255*sizeof(char));
    outDispl = (char*)malloc(255*sizeof(char));
    for (i = 0; i<255; i++) {
        variable[i] = ' ';
        outDispl[i] = ' ';
    }
    for (i = 0; i< 5; i++){
        variable[i] = '0';
    }
    n = 0;
    i = 5;
}

void MainWindow::on_pushButton_5_clicked()
{
    variable[i] = 's';
    i++;
    variable[i] = 'i';
    i++;
    variable[i] = 'n';
    i++;

    outDispl[n] = 's';
    n++;
    outDispl[n] = 'i';
    n++;
    outDispl[n] = 'n';
    n++;

    ui->label->setText(outDispl);
}

void MainWindow::on_pushButton_6_clicked()
{
    variable[i] = '3';
    i++;
    outDispl[n] = '3';
    n++;

    ui->label->setText(outDispl);
}

void MainWindow::on_pushButton_7_clicked()
{
    variable[i] = '4';
    i++;
    outDispl[n] = '4';
    n++;

    ui->label->setText(outDispl);
}

void MainWindow::on_pushButton_8_clicked()
{
    variable[i] = '5';
    i++;
    outDispl[n] = '5';
    n++;

    ui->label->setText(outDispl);
}

void MainWindow::on_pushButton_9_clicked()
{
    variable[i] = '6';
    i++;
    outDispl[n] = '6';
    n++;

    ui->label->setText(outDispl);
}

void MainWindow::on_pushButton_10_clicked()
{
    variable[i] = '7';
    i++;
    outDispl[n] = '7';
    n++;

    ui->label->setText(outDispl);
}

void MainWindow::on_pushButton_11_clicked()
{
    variable[i] = '8';
    i++;
    outDispl[n] = '8';
    n++;

    ui->label->setText(outDispl);
}

void MainWindow::on_pushButton_12_clicked()
{
    variable[i] = '9';
    i++;
    outDispl[n] = '9';
    n++;

    ui->label->setText(outDispl);
}

void MainWindow::on_pushButton_13_clicked()
{
    variable[i] = '-';
    i++;
    outDispl[n] = '-';
    n++;

    ui->label->setText(outDispl);
}

void MainWindow::on_pushButton_14_clicked()
{
    variable[i] = '*';
    i++;
    outDispl[n] = '*';
    n++;

    ui->label->setText(outDispl);
}

void MainWindow::on_pushButton_15_clicked()
{
    variable[i] = '/';
    i++;
    outDispl[n] = '/';
    n++;

    ui->label->setText(outDispl);
}

void MainWindow::on_pushButton_16_clicked()
{
    variable[i] = '(';
    i++;
    outDispl[n] = '(';
    n++;

    ui->label->setText(outDispl);
}

void MainWindow::on_pushButton_19_clicked()
{
    i--;
    variable[i] = ' ';
    n--;
    outDispl[n] = ' ';

    ui->label->setText(outDispl);
}
