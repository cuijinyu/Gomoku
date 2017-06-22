#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QDialog *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton *p1=ui->pushButton;
    QPushButton *p2=ui->pushButton_2;
    QPushButton *p3=ui->pushButton_3;
    QPushButton *p4=ui->pushButton_4;
    QPushButton *p5=ui->pushButton_5;
    p1->setStyleSheet("QPushButton{border:0px;border-radius:10px;width:80px;height:40px;}");
    p2->setStyleSheet("QPushButton{border:0px;border-radius:10px;width:80px;height:40px;}");
    p3->setStyleSheet("QPushButton{border:0px;border-radius:10px;width:80px;height:40px;}");
    p4->setStyleSheet("QPushButton{border:0px;border-radius:10px;width:80px;height:40px;}");
    p5->setStyleSheet("QPushButton{border:0px;border-radius:10px;width:80px;height:40px;}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
    qsingle.show();
    qsingle.exec();
    this->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->hide();
    qdouble.show();
    qdouble.exec();
    this->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    this->hide();
    qnetwork.show();
    qnetwork.exec();
    qnetwork.closeProcess();
    qnetwork.reSet();
    this->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    this->hide();
    qabout.show();
    qabout.exec();
    this->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    exit(1);
}
