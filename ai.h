#ifndef AI_H
#define AI_H

/*
    AI评估函数：
        1：对棋盘进行遍历对每个点进行检索（即将每个点周围情况用四个函数HorJudge，VerJudge，SprJudge，BacJudge进行存储）
        2：将存储好的各点的情况与评估函数按分值大小顺序进行匹配
        3：用上述方法对己方和对方分别评估，并存储在两个数组中，取较大值作为该点的分数
        4：最后对所有点分数进行比较，取值最大的点作为落子点，将值最大的点存储在数组中
*/

//int i,j;   //i代表纵轴，j代表横轴
class AI{
public:
    int a[15][15];		//棋盘
    int MSide;	//代表我方棋子的颜色
    int ChessBoard[4][2];		//表示四路的状态 第一个为两边情况 第二个为连子个数

    AI();
    void HorJudge(int ay,int ax,int side);     //横轴判断连子的个数 ay代表纵轴，ax代表横轴，num代表个数 chessboard[1]
    void VerJudge(int ay,int ax,int side);     //纵轴判断连子的个数 chessboard[2]
    void SprJudge(int ay,int ax,int side);     //'/'斜杠判断连子的个数 chessboard[3]
    void BacJudge(int ay,int ax,int side);     //'\'斜杠判断连子的个数 chessboard[4]

    bool Five(); 	//100
    bool A_four();	//90
    bool Double_D_four();	//90
    bool D_four_A_three();	//90
    bool Double_three();	//80
    bool D_three_A_three();	//70
    bool D_four();	//60
    bool A_three();	//50
    bool Double_A_two();	//40
    bool D_three();	//30
    bool A_two();		//20
    bool D_two();		//10 i88i8wq3
    bool One();	//0

    void judge();

    int xi,yi;
    int getx();
    int gety();
};

#endif // AI_H
