#include "network.h"
#include "ui_network.h"
network::network(QDialog *parent) :QDialog(parent),ui(new Ui::network)
{
    ui->setupUi(this);
//initialize chess board:0 represents blank,1 represents black,-1 represents white
    reSet();
//initialize terminated
    pal = new QPalette();
    Menu = new QMenu(this);
    menuBar = new QMenuBar(this);
    QPushButton* backBtn =ui->backBtn;
//    QPushButton* continueBtn = ui->containueBtn;
 //   QPushButton* stopBtn = ui->stopBtn;
    lineEdit = new QLineEdit(this);
    information_p1 = new QLabel(this);
    information_p2 = new QLabel(this);
    moveOrder=ui->label_3;
//  <background clor>
//    pal->setColor(QPalette::Background, Qt::white);
//    this->setAutoFillBackground(true);
//    this->setPalette(*pal);
//  <Menu>
    Menu->addAction(tr("新游戏"), this, SLOT(Play()), tr("Ctrl+N"));
    Menu->setTitle("菜单");
    menuBar->addMenu(Menu);
//  <windows>
 //   backBtn->setGeometry(QRect(750,730,150,50));
  //  backBtn->setFont(QFont("Times",10,QFont::Bold));
    QObject::connect(backBtn,SIGNAL(clicked()),this,SLOT(giveUp()));
     backBtn->setStyleSheet("border:0px;border-radius:10px;width:80px;height:40px;");
   // continueBtn->setGeometry(QRect(250,730,150,50));
   // continueBtn->setFont(QFont("Times",10,QFont::Bold));
//    QObject::connect(continueBtn,SIGNAL(clicked()),this,SLOT(Continue()));
//    continueBtn->setStyleSheet("border:0px;border-radius:10px;width:80px;height:40px;");
  //  stopBtn->setGeometry(500,730,150,50);
   // stopBtn->setFont(QFont("Times",10,QFont::Bold));
//    QObject::connect(stopBtn,SIGNAL(clicked()),this,SLOT(Stop()));
//     stopBtn->setStyleSheet("border:0px;border-radius:10px;width:80px;height:40px;");

     lineEdit->setGeometry(540,30,150,50);
     lineEdit->setStyleSheet("border:0;background:url(:/new/prefix1/chess.jpg);font: 75 12pt '微软雅黑';font-size:40px;");
   // information_p1->setFrameStyle(QFrame::Panel|QFrame::Sunken);
   // information_p1->setText("(20,180),(220,180)\n(20,580),(220,580)");
   // information_p1->setGeometry(20,180,200,400);
   // pal->setColor(QPalette::Background, Qt::black);

    //information_p2->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    //information_p2->setText("(980,180),(1180,180)\n(980,580),(1180,580)");
    //information_p2->setGeometry(980,180,200,400);
   // information_p2->setPalette(*pal);
}
// *********************************************************
network::~network()
{
    delete ui;
    delete pal;
    delete Menu;
    delete menuBar;
/*    delete backBtn;
    delete continueBtn;
    delete stopBtn;*/
    delete lineEdit;
    delete information_p1;
    delete information_p2;
    delete moveOrder;
    closeProcess();
}
void network::reSet()
{
    resetChessBoard();
    closeProcess();
    chess_color = 1;
    chess_order = 0;
    mouse_x = 0;
    mouse_y = 0;
    beginPlay = false;
    runTimeStop = false;
    mouse_press = 0;
//    allowTakeBack = false;
    ofstream out;
    out.open("./my.txt");
    out.close();
    out.open("./your.txt");
    out.close();
    out.open("./IP.txt");
    out.close();
    out.open("./myinformation.txt");
    out.close();
    out.open("./yourinformation.txt");
    out.close();
}
void network::Write()
{
    ofstream out;
    out.open("./my.txt",ios::out);
    out << chess_order << " " << chess_color << " " << mouse_x << " " << mouse_y;
    out.close();
}
bool network::Read()
{
    ifstream in;int temp_order;
    in.open("./your.txt",ios::in);
    in >> temp_order >> chess_color >> mouse_x >> mouse_y;
    if(!(mouse_x>=310&&mouse_x<=890&&mouse_y>=90&&mouse_y<=670))
    {
        in.close();
        return false;
    }
    if(temp_order == chess_order+1)
    {
        chess_order = temp_order;
        in.close();
        return true;
    }
    in.close();
    return false;
}
void network::sendMessage(int temp)
{
    ofstream out;
    out.open("./myinformation.txt",ios::out);
    out << temp << endl;
    out.close();
    //只请求一次
    out.open("./myinformation.txt",ios::out);
    out.close();
}
void network::getMessage()
{
    // 1000 represents give up,1111 represents take back,1112 represents not allow,-1111 represents allow taking back,9999 represent black win,-9999 represent white win
    ifstream in;
    in.open("./yourinformation.txt",ios::in);
    int temp;
    in >> temp;
    if(temp == EOF)
        return;
    switch(temp)
    {
        case 1000:
        {
            beginPlay = false;
            if(myTurn == 0)
            {
                lineEdit->setText("黑子胜!");
            }
            else if(myTurn == 1)
            {
                lineEdit->setText("白子胜!");
            }
            break;
        }
        case 9999:
        {
            beginPlay = false;
            lineEdit->setText("黑子胜!");
            break;
        }
        case -9999:
        {
            beginPlay = false;
            lineEdit->setText("白子胜!");
            break;
        }
        case 1111:
        {
            QMessageBox messageBox(QMessageBox::Warning,"悔棋提示","允许对方悔棋？",QMessageBox::Yes|QMessageBox::No,NULL);
            if(messageBox.exec() == QMessageBox::Yes)
            {
                sendMessage(-1111);
                if(chess_order%2 == myTurn)
                {
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
                else
                {
                    int times = 0;
                    for(int i=0;i<15;i++)
                        for(int j=0;j<15;j++)
                        {
                            if(chess[i][j][1] == chess_order)
                            {
                                chess[i][j][1] = 0;
                                chess[i][j][0] = 0;
                                chess_order--;
                                chess_color = -chess_color;
                                times++;
                            }
                            if(times == 2)
                                return;
                        }
                }
            }
            else
                sendMessage(1112);
            break;
        }
        case -1111:
        {
//            allowTakeBack = true;
            break;
        }
        case 1112:
        {
            QMessageBox messageBox(QMessageBox::Warning,"悔棋提示","对方拒绝您悔棋",QMessageBox::Yes,NULL);
            messageBox.exec();
            break;
        }
    }
    ofstream out;
    out.open("./yourinformation.txt",ios::out);
    out.close();
}
void network::closeProcess()
{
    if(presentProcess == "server.exe")
        WinExec("taskkill /im server.exe",SW_HIDE);
    else if(presentProcess == "client.exe")
        WinExec("taskkill /im client.exe",SW_HIDE);
}
//  <slots>
void network::Play()
{
    //myTurn: 先手为0，为黑子，后手为1，为白子
    reSet();
    lineEdit->setText("");
    beginPlay = true;
    STARTUPINFO si;
    memset(&si,0,sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);
    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_HIDE;
    QMessageBox messageBox(QMessageBox::Warning,"选择提示","      是否先手？",QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel,NULL);
    messageBox.setStyleSheet("font:14pt");
    int message = messageBox.exec();
    if(message == QMessageBox::Yes)
    {
        bool isOK;
        QString text = QInputDialog::getText(NULL,"IP","请输入对方IP地址",QLineEdit::Normal,"0.0.0.0",&isOK);
        if(isOK)
        {
            QMessageBox messageBox(QMessageBox::Warning,"信息","请提示对方选择后手",QMessageBox::Yes|QMessageBox::Cancel,NULL);
            messageBox.exec();
            ofstream out;
            out.open("./IP.txt");
            out << text.toStdString();
            out.close();
            TCHAR szCommandLine[] = TEXT("./client.exe");
            hCildThread = CreateProcess(NULL,szCommandLine,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi);
            presentProcess = "client.exe";
            myTurn = 0;
        }
        else
        {
            beginPlay = false;
            return;
        }
    }
    else if(message == QMessageBox::No)
    {
        QMessageBox messageBox(QMessageBox::Warning,"信息","请提示对方选择先手",QMessageBox::Yes|QMessageBox::Cancel,NULL);
        messageBox.exec();
        TCHAR szCommandLine[] = TEXT("./server.exe");
        hCildThread = CreateProcess(NULL,szCommandLine,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi);
        presentProcess = "server.exe";
        myTurn = 1;
    }
    else
    {
        beginPlay = false;
        return;
    }
}
/*void network::Continue()
{
    if(runTimeStop)
    {
        beginPlay = true;
        runTimeStop = false;
    }
}
void network::Stop()
{
    if(beginPlay)
    {
        runTimeStop = true;
        beginPlay = false;
    }
}
void network::takeBack()
{
    if(beginPlay)
    {
        if(chess_order == 0)
            return;
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
}*/
void network::giveUp()
{
    if(beginPlay)
    {
        beginPlay = false;
        closeProcess();
        if(myTurn == 0)
        {
            lineEdit->setText("白子胜!");
        }
        else if(myTurn == 1)
        {
            lineEdit->setText("黑子胜!");
        }
        sendMessage(1000);
    }
}
//  <chess board>
void network::mousePressEvent(QMouseEvent *m)
{
     if(beginPlay)
     {
         if(chess_order%2 == myTurn)
         {
             if(m->pos().x()>=310&&m->pos().x()<=890&&m->pos().y()>=90&&m->pos().y()<=670)
             {
                 mouse_x = m->pos().x();
                 mouse_y = m->pos().y();
                 mouse_press = 1;
             }
         }
     }
 //   lineEdit->setText(tr("  %1,%2").arg(m->pos().x()).arg(m->pos().y()));
}
void network::keyPressEvent(QKeyEvent *k)
{
    if(k->key() == Qt::Key_A)
        exit(1);
}
int network::Win()
{
    if(beginPlay)
    {
        if(chess_order%2 == myTurn)
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
    }
    return 0;
}
void network::resetChessBoard()
{
    for(int i=0;i<SIZE+1;i++)
        for(int j=0;j<SIZE+1;j++)
            for(int k=0;k<2;k++)
                chess[i][j][k] = 0;
}

void network::paintEvent(QPaintEvent *)
{
    if(beginPlay)
    {
        if(chess_order%2 == 0)
            moveOrder->setText("黑方下子");
        else if(chess_order%2 == 1)
            moveOrder->setText("白方下子");
    }
    if(beginPlay)
        getMessage();
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
    if(mouse_press == 1)
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
                    }
                    // record the accurate mouse location to judge whether win or not
                    mouse_x = x;
                    mouse_y = y;
                }
        mouse_press = 0;
        Write();
        //发送chess_order,chess_color,mouse_x,mouse_y
    }
    else if(mouse_press == 0)
    {
        if(Read())
        {
            chess[toVirtualX(mouse_x)][toVirtualY(mouse_y)][0] = -chess_color;
            chess[toVirtualX(mouse_x)][toVirtualY(mouse_y)][1] = chess_order;
        }
        /*
         * 接收chess_order,chess_color,mouse_x,mouse_y
         * 并做chess[toVirtualX(mouse_x)][toVirtualY(mouse_y)][0]=-chess_color;
         * chess[toVirtualX(mouse_x)][toVirtualY(mouse_y)][1]=chess_order;
         */
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
        {
            lineEdit->setText("黑子胜!");
            sendMessage(9999);
        }
        else if(signal == -1)
        {
            lineEdit->setText("白子胜!");
            sendMessage(-9999);
        }
        beginPlay = false;
        moveOrder->setText("");
        closeProcess();
    }
    paint->end();
}
//  <坐标映射>
int network::toRealX(int virtualX)
{
    return 40*virtualX+320;
}

int network::toRealY(int virtualY)
{
    return 40*virtualY+100;
}

int network::toVirtualX(int realX)
{
    return (realX-320)/40;
}

int network::toVirtualY(int realY)
{
    return (realY-100)/40;
}
