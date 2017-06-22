#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "about.h"
#include "network.h"
#include "doubled.h"
#include "about.h"
#include "single.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QDialog *parent = 0);
    ~MainWindow();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
private:
    Ui::MainWindow *ui;
    single qsingle;
    doubled qdouble;
    network qnetwork;
    about qabout;
};

#endif // MAINWINDOW_H
