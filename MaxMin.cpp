/***
***
*** 以下部分实现了MaxMin搜索
**
***/
#include"MaxMin.h"
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include"point.h"
#define WHITE -1
#define BLACK 1
using namespace std;
//#include"AI.h"
//极大极小值搜索
int MaxMin::MinMax(int depth,int alpha,int beta)
{//
	if(SideToMove()==WHITE)
	{
		return Max(depth);//因为从计算机的角度来评估
	}else
	{
		return Min(depth);
	}
}


int MaxMin::Max(int depth,int alpha,int beta)
{
	flagMove=0;
	int best=-INFINITY;
	if (depth<=0)
	{
		return Evaluate();
		/* code */
	}
	GenerateLegalMoves();
	while(MovesLeft())//遍历所有着点
	{
		MakeNextMove();//实施着法
		val=Min(depth-1,alpha,best>alpha?best:alpha);
		UnMakeMoves();//撤销当前走法
		if (val>best)
		{
			/* code */
			best=val;
		}
		if(val>alpha)
		{
			ABcut++;
			break;
		}
	}
	return best;
}

int MaxMin::Min(int depth)
{
	flagMove=0;
	int best=INFINITY;
	int value=Evaluate();
	if (depth<=0)
	{
		/* code */
		return Evaluate();
	}
	GenerateLegalMoves();
	while(MovesLeft())//遍历所有着点
	{
		MakeNextMove();//实施着法
		val=Max(depth-1,best<alpha?best,alpha,beta);
		UnMakeMoves();//撤销着法
		if(val<best)
		{
			best=val;
		}
		if(val<beta)
		{
			//alpha-beta剪枝
			ABcut++;
			break;
		}
	}
	return best;
}

//生成每一步有空位的点
int MaxMin::GenerateLegalMoves()
{
	//清空以前存储位置数组中存储的信息
	if(flag>0){	
		for(int i=0;i<=flag;i++)
		{
			for(int j=0;j<=flag;j++)
			{
				points[flag].x=-1;
				points[flag].y=-1;
			}
		}
	};
	//重新标志位置，并存储新的信息
	flag=0;
	for(int i=0;i<15;i++)
	{
		for (int j = 0; j < 15; j++)
		{
			/* code */
			if(board[i][j]==0)
			{
				points[flag].x=i;
				points[flag].y=j;
				flag++;		
			}
		}
	}
}

//尝试下一个子
void MaxMin::MakeNextMove()
{
		tryOne=0;
		srand((unsigned)time(NULL));
		tryOne=rand()%(flag+1);
		color=SideToMove();
		board[tryOne][tryOne]=color;
}

//取消当前尝试下的子
void MaxMin::UnMakeMoves()
{
		board[tryOne][tryOne]=0;
}


//遍历所有可以下的棋子
bool MaxMin::MovesLeft()
{ 
	if(flagMove<flag)
	{
		if(x[flagMove]>=0)
		{
			flagMove++;
			return true;
		}else
		{
			return false;
		}
	}else
	{
		return false;
	}	
}

//判断当前下子方函数
int MaxMin::SideToMove()
{
	if(color==1)
	{
		return WHITE;
	}else if(color==-1)
	{	
		return BLACK;
	}
}
//Evaluate函数的实现
int MaxMin::Evaluate()
{
	return 0;
};
