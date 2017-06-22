#ifndef network_H
#define network_H

#include <QDialog>
#include <QtGui>
#include "button.h"
#include <qfont.h>
#include <QWidget>
#include <qcolor.h>
#include <qedit.h>
#include <QLineEdit>
#include <qlabel.h>
#include <QMenu>
#include <QMenuBar>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QAction>
#include <QPalette>
#include <QMessageBox>
#include <QCursor>
#include <QPainter>
#include <cstring>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <QInputDialog>
using namespace std;

namespace Ui
{
    class network;
}

class network : public QDialog
{
    Q_OBJECT

    public:
        explicit network(QDialog *parent = 0);
        ~network();
    private slots:
        void Play();
/*        void Continue();
        void Stop();
        void takeBack();*/
        void giveUp();
    private:
        Ui::network *ui;
        //布局
        //颜色
        QPalette* pal;
        //菜单
        QMenu* Menu;
        QMenuBar* menuBar;
        //控件
/*        Button* backBtn;
        Button* giveUpBtn;
        Button* continueBtn;
        Button* stopBtn;*/
        QLineEdit* lineEdit;
        QLabel* information_p1;
        QLabel* information_p2;
        QInputDialog inputIP;
        //棋盘
        QPainter* paint;
        const static int SIZE=14;
        const static int WIDTH=40;
        const static int x=320,y=100;
        int mouse_x,mouse_y,mouse_press,chess_color,chess_order;
        bool beginPlay,runTimeStop;
        void mousePressEvent(QMouseEvent *m);
        void keyPressEvent(QKeyEvent *k);
        int Win();
        void resetChessBoard();
        void paintEvent(QPaintEvent *);
        int chess[SIZE+1][SIZE+1][2];
        QLabel *moveOrder;
        //坐标映射
        int toRealX(int virtualX);
        int toRealY(int virtualY);
        int toVirtualX(int realX);
        int toVirtualY(int realY);
        //对战
        int myTurn;
        PROCESS_INFORMATION pi;
        DWORD hCildThread;
        void Write();
        bool Read();
        void sendMessage(int temp);
        void getMessage();
        void tackBack();
        string presentProcess;
public:
        void closeProcess();
        void reSet();
};

#endif // network_H
