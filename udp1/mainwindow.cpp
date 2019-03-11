#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    soket = new QUdpSocket;
    soket->bind(QHostAddress::LocalHost, 1234);
    QObject::connect(soket,SIGNAL(readyRead()),this,SLOT(hazir()));

}

MainWindow::~MainWindow()
{
    delete ui;

    k=0;
}

void MainWindow::hazir()
{
    while(false != soket->hasPendingDatagrams())
    {

    QByteArray veri;
    veri.resize(soket->pendingDatagramSize());

    QHostAddress adres;
    quint16 port;

    soket->readDatagram(veri.data(),veri.size(),&adres,&port);

    qDebug() << "Bir paket alındı.";
    qDebug() << "Adresi:" << adres;
    qDebug() << "Portu:" << port;
    qDebug() << "Veri:" << veri;

    k= k+1;
    qDebug() << "sayi:" << k;

    ui ->label->setText(veri);

    }
}
