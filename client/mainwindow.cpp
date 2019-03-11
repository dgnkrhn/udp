#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <sstream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    k = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{

    ui -> xlabel -> setText(QString::number(value));
    QByteArray veri;

    haberlesme = QString::number(value);
    soket = new QUdpSocket;
    veri.append(haberlesme);
    soket->writeDatagram(veri,QHostAddress::LocalHost, 1234);
    k= k+1;
    qDebug() << "sayi:" << k;


}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QByteArray veri;

    haberlesme = arg1;
    soket = new QUdpSocket;
    veri.append(haberlesme);
    soket->writeDatagram(veri,QHostAddress::LocalHost, 1234);
    k= k+1;
    qDebug() << "sayi:" << k;
}
