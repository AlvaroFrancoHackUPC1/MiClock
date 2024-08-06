#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString newAlarm = ui->timeEdit->text();
    ui->listAlarm->insertItem(0, newAlarm);

    ui->timeEdit->setTime(QTime(00, 00, 00));
}

