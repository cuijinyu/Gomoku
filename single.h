#ifndef SINGLE_H
#define SINGLE_H

#include <QDialog>

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

#include "ai.h"

class AI;

namespace Ui
{
    class single;
}

class single : public QDialog
{
    Q_OBJECT

    public:
        explicit single(QDialog *parent = 0);
        ~single();
        //single();     //内嵌构造函数
        void linked();         //将chess数组传给a
        void geta();         //将a传给chess
    private slots:
        void Play();
        void Continue();
        void Stop();
        void takeBack();
    private:
        Ui::single *ui;
        //布局
        //颜色
        QPalette* pal;
        //菜单
        QMenu* Menu;
        QMenuBar* menuBar;
        //控件
        Button* backBtn;
        Button* continueBtn;
        Button* stopBtn;
        QLineEdit* lineEdit;
        QLabel* information_p1;
        QLabel* information_p2;
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
        //坐标映射
        int toRealX(int virtualX);
        int toRealY(int virtualY);
        int toVirtualX(int realX);
        int toVirtualY(int realY);
        //网络对战
        QLabel *moveOrder;
        bool myTurn,yourTurn;
        //void linked();         //将chess数组传给a
        //void geta();         //将a传给chess
        int xx,yy;
        AI ai;
};

#endif // NETWORK_H
