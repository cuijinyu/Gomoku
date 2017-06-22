#include "ai.h"
#include <string.h>
#include <cstdlib>

AI::AI()
{
    memset(a,0,sizeof(a));
    memset(ChessBoard,0,sizeof(ChessBoard));
    MSide=-1;
    xi=0;
    yi=0;
}

void AI::HorJudge(int ay,int ax,int side)   //(ay,ax)表示当前要检索的点坐标，side表示白或者黑子，即本方
{
    a[ay][ax]=side;
    int i=ax;               //试下当前点
    while(i>=0&&a[ay][i]==side)           //左
    {
        ChessBoard[0][1]++;
        i--;
    }
    if(i<0)
        ChessBoard[0][0]++;
    else
    if(a[ay][i]!=0)
        ChessBoard[0][0]++;


    i=ax+1;								//右
    while(i<15&&a[ay][i]==side)
    {
        ChessBoard[0][1]++;
        i++;
    }
    if(i>=15)
        ChessBoard[0][0]++;
    else
    if(a[ay][i]!=0)
        ChessBoard[0][0]++;

    a[ay][ax]=0;          //当前点置零
}

void AI::VerJudge(int ay,int ax,int side)
{
    a[ay][ax]=side;
    int i=ay;

    while(i>=0&&a[i][ax]==side)
    {
        ChessBoard[1][1]++;
        i--;
    }
    if(i<0)
        ChessBoard[1][0]++;
    else
    if(a[i][ax]!=0)
    {
        ChessBoard[1][0]++;
    }

    i=ay+1;
    while(i<15&&a[i][ax]==side)
    {
        ChessBoard[1][1]++;
        i++;
    }
    if(i>=15)
        ChessBoard[1][0]++;
    else
    if(a[i][ax]!=0)
        ChessBoard[1][0]++;

    a[ay][ax]=0;
}

void AI::SprJudge(int ay,int ax,int side)
{
    a[ay][ax]=side;
    int i=ay,j=ax;
    while(i>=0&&j<15&&a[i][j]==side)
    {
        ChessBoard[2][1]++;
        i--;
        j++;
    }
    if(i<0||j>=15)
        ChessBoard[2][0]++;
    else
    if(a[i][j]!=0)
        ChessBoard[2][0]++;

    i=ay+1;
    j=ax-1;
    while(i<15&&j>=0&&a[i][j]==side)
    {
        ChessBoard[2][1]++;
        i++;
        j--;
    }
    if(i>=15||j<0)
        ChessBoard[2][0]++;
    else
    if(a[i][j]!=0)
    {
        ChessBoard[2][0]++;
    }

    a[ay][ax]=0;
}

void AI::BacJudge(int ay,int ax,int side)
{
    a[ay][ax]=side;
    int i=ay;
    int j=ax;
    while(i>=0&&j>=0&&a[i][j]==side)
    {
        ChessBoard[3][1]++;
        i--;
        j--;
    }
    if(i<0||j<0||a[i][j]!=0)
        ChessBoard[3][0]++;

    i=ay+1;
    j=ax+1;
    while(i<15&&j<15&&a[i][j]==side)
    {
        ChessBoard[3][1]++;
        i++;
        j++;
    }
    if(i>=15||j>=15||a[i][j]!=0)
        ChessBoard[3][0]++;

    a[ay][ax]=0;
}

bool AI::Five()
{
    int i=0;
    for(i=0;i<4;i++)
    {
        if(ChessBoard[i][1]==5)
            return true;          
    }
    return false;
}

bool AI::A_four()
{
    int i=0;
    for(i=0;i<4;i++)
    {
        if(ChessBoard[i][1]==4&&ChessBoard[i][0]==0)
            return true;
    }
    return false;
}

bool AI::Double_D_four()
{
    int i;
    int number=0;
    for(i=0;i<4;i++)
    {
        if(ChessBoard[i][1]==4&&ChessBoard[i][0]==1)
            number++;
    }

    if(number>=2)
        return true;
    else
        return false;
}

bool AI::D_four_A_three()
{
    int i;
    int number=0;
    for(i=0;i<4;i++)
    {
        if((ChessBoard[i][1]==4&&ChessBoard[i][0]==1)||(ChessBoard[i][1]==3&&ChessBoard[i][0]==0))
            number++;
    }

    if(number>=2)
        return true;
    else
        return false;
}

bool AI::Double_three()
{
    int i;
    int number=0;
    for(i=0;i<4;i++)
    {
        if(ChessBoard[i][1]==3&&ChessBoard[i][0]==0)
            number++;
    }
    if(number>=2)
        return true;
    else
        return false;
}

bool AI::D_three_A_three()
{
    int i;
    int number=0;
    for(i=0;i<4;i++)
    {
        if((ChessBoard[i][1]==3&&ChessBoard[i][0]==0)||(ChessBoard[i][1]==3&&ChessBoard[i][0]==1))
            number++;
    }
    if(number>=2)
        return true;
    else
        return false;
}

bool AI::D_four()
{
    int i=0;
    for(i=0;i<4;i++)
    {
        if(ChessBoard[i][1]==4&&ChessBoard[i][0]==1)
            return true;
    }
    return false;
}

bool AI::A_three()
{
    int i=0;
    for(i=0;i<4;i++)
    {
        if(ChessBoard[i][1]==3&&ChessBoard[i][0]==0)
            return true;
    }
    return false;
}

bool AI::Double_A_two()
{
    int i;
    int number=0;
    for(i=0;i<4;i++)
    {
        if(ChessBoard[i][1]==2&&ChessBoard[i][0]==1)
            number++;
    }
    if(number>=2)
        return true;
    else
        return false;
}

bool AI::D_three()
{
    int i=0;
    for(i=0;i<4;i++)
    {
        if(ChessBoard[i][1]==3&&ChessBoard[i][0]==1)
            return true;
    }
    return false;
}

bool AI::A_two()
{
    int i=0;
    for(i=0;i<4;i++)
    {
        if(ChessBoard[i][1]==2&&ChessBoard[i][0]==0)
            return true;
    }
    return false;
}

bool AI::D_two()
{
    int i=0;
    for(i=0;i<4;i++)
    {
        if(ChessBoard[i][1]==2&&ChessBoard[i][0]==1)
            return true;
    }
     return false;
}

bool AI::One()
{
    int i=0;
    for(i=0;i<4;i++)
    {
        if(ChessBoard[i][1]==1&&ChessBoard[i][0]<=1)
            return true;
    }
    return false;
}


void AI::judge()  //评估函数
{
    int b[15][15];
    int c[15][15];
    int temp[15][15];

    for(int p=0;p<15;p++)
    {
        for(int q=0;q<15;q++)
        {
            b[p][q]=-1;
            c[p][q]=-1;
            temp[p][q]=-1;
        }
    }
    int max=0;
    int finalx[255];
    int finaly[255];
    int t=0;
    int r=0;


    int i,j;
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            if(a[i][j]==0)
            {
                b[i][j]=a[i][j];
                c[i][j]=a[i][j];

                HorJudge(i,j,MSide);
                VerJudge(i,j,MSide);
                SprJudge(i,j,MSide);
                BacJudge(i,j,MSide);

                if(Five())       //己方价值评估
                    b[i][j]=101;
                else
                if(A_four())
                    b[i][j]=91;
                else
                if(Double_D_four())
                    b[i][j]=91;
                else
                if(D_four_A_three())
                    b[i][j]=91;
                else
                if(Double_three())
                    b[i][j]=81;
                else
                if(D_three_A_three())
                    b[i][j]=71;
                else
                if(D_four())
                    b[i][j]=61;
                else
                if(A_three())
                    b[i][j]=51;
                else
                if(Double_A_two())
                    b[i][j]=41;
                else
                if(D_three())
                    b[i][j]=31;
                else
                if(A_two())
                    b[i][j]=21;
                else
                if(D_two())
                    b[i][j]=11;
                else
                if(One())
                    b[i][j]=1;

                memset(ChessBoard,0,sizeof(ChessBoard));

                HorJudge(i,j,-MSide);
                VerJudge(i,j,-MSide);
                SprJudge(i,j,-MSide);
                BacJudge(i,j,-MSide);

                if(Five()) 	//对方价值评估
                    c[i][j]=100;
                else
                if(A_four())
                    c[i][j]=90;
                else
                if(Double_D_four())
                    c[i][j]=90;
                else
                if(D_four_A_three())
                    c[i][j]=90;
                else
                if(Double_three())
                    c[i][j]=80;
                else
                if(D_three_A_three())
                    c[i][j]=70;
                else
                if(D_four())
                    c[i][j]=60;
                else
                if(A_three())
                    c[i][j]=50;
                else
                if(Double_A_two())
                    c[i][j]=40;
                else
                if(D_three())
                    c[i][j]=30;
                else
                if(A_two())
                    c[i][j]=20;
                else
                if(D_two())
                    c[i][j]=10;
                else
                if(One())
                    c[i][j]=0;

                memset(ChessBoard,0,sizeof(ChessBoard));

                if(c[i][j]>b[i][j])
                    temp[i][j]=c[i][j];
                else
                    temp[i][j]=b[i][j];
                //temp[i][j]=(c[i][j]>b[i][j])?c[i][j]:b[i][j];
            }
        }
    }


    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            if(temp[i][j]>max)
            {
                max=temp[i][j];
            }
        }
    }

    if(max==0)
    {
        xi=7;
        yi=7;
    }
    else
    {
        for(i=0;i<15;i++)
        {
            for(j=0;j<15;j++)
            {
                if(temp[i][j]==max)
                {
                    finalx[t]=j;       //将分数最高的点赋值1，作为传入值
                    finaly[t]=i;
                    t++;
                }
            }
        }
        r=rand()%t;
        if(finalx[r]>=0 && finalx[r]<15 &&finaly[r]>=0 && finaly[r]<15)
        {
            xi=finalx[r];
            yi=finaly[r];
        }
    }

}

int AI::getx()
{
    return xi;
}

int AI::gety()
{
    return yi;
}











