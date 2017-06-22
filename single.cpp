#include "single.h"
#include "ui_single.h"
#include "QMessageBox"


single::single(QDialog *parent) :QDialog(parent),ui(new Ui::single),ai()
{
    ui->setupUi(this);
/*    QMessageBox messageBox(QMessageBox::Warning,"Information","Really to start?",QMessageBox::Yes|QMessageBox::No,NULL);
    if (messageBox.exec()!=QMessageBox::Yes)
        exit(1);*/
//initialize chess board:0 represents blank,1 represents black,-1 represents white

    resetChessBoard();
    chess_color = 1;
    beginPlay = false;
    runTimeStop = false;
    chess_order = 0;
//initialize terminated
    pal = new QPalette();
    Menu = new QMenu(this);
    menuBar = new QMenuBar(this);
    QPushButton *backBtn =ui->backBtn;
    QPushButton *continueBtn = ui->containueBtn;
    QPushButton *stopBtn = ui->stopBtn;
     moveOrder=ui->label_3;
    lineEdit = new QLineEdit(this);
   // information_p1 = new QLabel(this);
    //information_p2 = new QLabel(this);
//  <background clor>
    pal->setColor(QPalette::Background, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(*pal);
//  <Menu>
    Menu->addAction(tr("新游戏"), this, SLOT(Play()), tr("Ctrl+N"));
    //Menu->addAction(tr("退出"), qApp, SLOT(quit()), tr("Ctrl+Q"));
    Menu->setTitle("菜单");

    menuBar->addMenu(Menu);
//  <windows>
    QObject::connect(backBtn,SIGNAL(clicked()),this,SLOT(takeBack()));
    backBtn->setStyleSheet("border:0px;border-radius:10px;width:80px;height:40px;");


    QObject::connect(continueBtn,SIGNAL(clicked()),this,SLOT(Continue()));
    continueBtn->setStyleSheet("border:0px;border-radius:10px;width:80px;height:40px;");

    QObject::connect(stopBtn,SIGNAL(clicked()),this,SLOT(Stop()));
    stopBtn->setStyleSheet("border:0px;border-radius:10px;width:80px;height:40px;");

    lineEdit->setGeometry(540,30,150,50);
    lineEdit->setStyleSheet("border:0;background:url(:/new/prefix1/chess.jpg);font: 75 12pt '微软雅黑';font-size:40px;");
   // information_p1->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    //information_p1->setText("(20,180),(220,180)\n(20,580),(220,580)");
    //information_p1->setGeometry(20,180,200,400);
    //pal->setColor(QPalette::Background, Qt::black);

    //information_p2->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    //information_p2->setText("(980,180),(1180,180)\n(980,580),(1180,580)");
    //information_p2->setGeometry(980,180,200,400);
   // information_p2->setPalette(*pal);
    myTurn=1;

    xx=0;
    yy=0;
}
/*single::single():ai()
{
}*/

void single::geta()
{
    for(int i=0;i<15;i++)          //列
    {
        for(int j=0;j<15;j++)    //行
        {
            chess[j][i][0]=ai.a[i][j];
        }
    }
}

void single::linked()
{
    int i,j;
    for(i=0;i<15;i++)          //列
    {
        for(j=0;j<15;j++)      //行
        {
            ai.a[i][j]=chess[j][i][0];
        }
    }
}

// *********************************************************
single::~single()
{
    delete ui;
    delete pal;
    delete Menu;
    delete menuBar;
    delete backBtn;
    delete continueBtn;
    delete stopBtn;
    delete lineEdit;
    delete information_p1;
    delete information_p2;
}
//  <slots>
void single::Play()
{
    resetChessBoard();
    lineEdit->setText("");
    beginPlay = true;
    chess_color = 1;
    chess_order = 0;
    mouse_x = 0;
    mouse_y = 0;
}
void single::Continue()
{
    if(runTimeStop)
    {
        beginPlay = true;
        runTimeStop = false;
    }
}
void single::Stop()
{
    if(beginPlay)
    {
        runTimeStop = true;
        beginPlay = false;
    }
}
void single::takeBack()
{
    if(beginPlay)
    {
        if(chess_order == 0)
            return;
        int times = 0;
        for(int i=0;i<15;i++)
            for(int j=0;j<15;j++)
                if(chess[i][j][1] == chess_order)
                {
                    chess[i][j][1] = 0;
                    chess[i][j][0] = 0;
                    chess_order--;
                    chess_color = -chess_color;
                    goto second;
                }
        second:
        for(int i=0;i<15;i++)
            for(int j=0;j<15;j++)
                if(chess[i][j][1] == chess_order)
                {
                    chess[i][j][1] = 0;
                    chess[i][j][0] = 0;
                    chess_order--;
                    chess_color = -chess_color;
                    return;
                }
    }
}
//  <chess board>
void single::mousePressEvent(QMouseEvent *m)
{
    if(beginPlay)
    {
        mouse_x = m->pos().x();
        mouse_y = m->pos().y();
        mouse_press = 1;
    }
    //lineEdit->setText(tr("  %1,%2").arg(m->pos().x()).arg(m->pos().y()));
    //repaint();
}

void single::keyPressEvent(QKeyEvent *k)
{
    if(k->key() == Qt::Key_A)
        exit(1);
}

int single::Win()
{
    if(beginPlay)
    {
        int times=1,x = toVirtualX(mouse_x),y = toVirtualY(mouse_y);int color = chess[x][y][0];
        //横向
        while(chess[--x][y][0] == color && times < 5)
            times++;
        x = toVirtualX(mouse_x);
        while(chess[++x][y][0] == color && times < 5)
            times++;
        if(times == 5)
            return color;
        x = toVirtualX(mouse_x);
        //纵向
        times = 1;
        while(chess[x][--y][0] == color && times < 5)
            times++;
        y = toVirtualY(mouse_y);
        while(chess[x][++y][0] == color && times < 5)
            times++;
        if(times == 5)
            return color;
        y = toVirtualY(mouse_y);
        //左斜
        times = 1;
        while(chess[--x][--y][0] == color && times < 5)
            times++;
        x = toVirtualX(mouse_x);y = toVirtualY(mouse_y);
        while(chess[++x][++y][0] == color && times < 5)
            times++;
        if(times == 5)
            return color;
        x = toVirtualX(mouse_x);y = toVirtualY(mouse_y);
        //右斜
        times = 1;
        while(chess[--x][++y][0] == color && times < 5)
            times++;
        x = toVirtualX(mouse_x);y = toVirtualY(mouse_y);
        while(chess[++x][--y][0] == color && times < 5)
            times++;
        if(times == 5)
            return color;
    }
    return 0;
}

void single::resetChessBoard()
{
    for(int i=0;i<SIZE+1;i++)
        for(int j=0;j<SIZE+1;j++)
            for(int k=0;k<2;k++)
                chess[i][j][k] = 0;
}

void single::paintEvent(QPaintEvent *)
{
    if(beginPlay)
    {
        if(chess_order%2 == 0)
            moveOrder->setText("黑方下子");
        else if(chess_order%2 == 1)
            moveOrder->setText("白方下子");
    }
    paint = new QPainter;
    paint->begin(this);
    paint->setPen(QPen(Qt::black,2,Qt::SolidLine));//钢笔工具：颜色，线号，实线
    //画SIZE+1条横线
    for(int i=0;i<SIZE+1;i++)
    {
        paint->drawLine(x,y+WIDTH*i,x+WIDTH*(SIZE),y+WIDTH*i);//画线函数：x1,y1,x2,y2:画从(x1,y1)到(x2,y2)的线
    }
    //画SIZE+1条竖线
    for(int i=0;i<SIZE+1;i++)
    {
        paint->drawLine(x+WIDTH*i,y,x+WIDTH*i,y+WIDTH*(SIZE));
    }
    /*int an=0;
    an=an+100;
    chess[an][15][0]=10;*/
    if(beginPlay)
    {
        if(myTurn == chess_order%2)
        {
            linked();
            ai.judge();
            xx=ai.getx();
            yy=ai.gety();
            //lineEdit->setText(tr("%1,%2").arg(yy).arg(xx));
            if(xx>=0&&xx<15&&yy>=0&&yy<15)
            {
                if(chess[xx][yy][0] == 0)
                {
                    chess[xx][yy][0] = chess_color;
                    chess_color = -chess_color;
                    chess[xx][yy][1] = ++chess_order;
                    // record the accurate mouse location to judge whether win or not
                    mouse_x = toRealX(xx);
                    mouse_y = toRealY(yy);
                }
            }
        }
        else
        {
            if(mouse_press)
            {
                if(mouse_x>=310&&mouse_x<=890&&mouse_y>=90&&mouse_y<=670)
                {
                    int x,y;
                    for(x=320;x<=880;x+=40)
                        for(y=100;y<=660;y+=40)
                            if(x-10<=mouse_x&&mouse_x<=x+10&&y-10<=mouse_y&&mouse_y<=y+10)
                            {
                                if(chess[toVirtualX(x)][toVirtualY(y)][0] == 0)
                                {
                                    chess[toVirtualX(x)][toVirtualY(y)][0] = chess_color;
                                    chess_color = -chess_color;
                                    chess[toVirtualX(x)][toVirtualY(y)][1] = ++chess_order;
                                    // record the accurate mouse location to judge whether win or not
                                    mouse_x = x;
                                    mouse_y = y;
                                }
                            }
                    mouse_press = 0;
                }
            }
        }
    }
    for(int x=0;x<SIZE+1;x++)
        for(int y=0;y<SIZE+1;y++)
            if(chess[x][y][0] == 1)
            {
                paint->setBrush(QBrush(Qt::black,Qt::SolidPattern));//毛刷：颜色，实图案
                paint->drawEllipse(toRealX(x)-15,toRealY(y)-15,30,30);//画椭圆：中心点X,Y,宽度，高度
            }
            else if(chess[x][y][0] == -1)
            {
                paint->setBrush(QBrush(Qt::white,Qt::SolidPattern));//毛刷：颜色，实图案
               paint->drawEllipse(toRealX(x)-15,toRealY(y)-15,30,30);//画椭圆：中心点X,Y,宽度，高度
            }
    update();
    if(int signal = Win())
    {
        if(signal == 1)
            lineEdit->setText("黑子胜!");
        else if(signal == -1)
            lineEdit->setText("白子胜!");
        beginPlay = false;
        mouse_x = 0;
        mouse_y = 0;
    }
}
//  <坐标映射>
int single::toRealX(int virtualX)
{
    return 40*virtualX+320;
}

int single::toRealY(int virtualY)
{
    return 40*virtualY+100;
}

int single::toVirtualX(int realX)
{
    return (realX-320)/40;
}

int single::toVirtualY(int realY)
{
    return (realY-100)/40;
}
