/***
***
*** 以下部分实现了MaxMin搜索
**
***/
#include"MaxMin.h"
#include"AI.h"
//极大极小值搜索
int MaxMin::MinMax(int board[15][15],int depth)
{
	return Max(depth);//因为从计算机胡角度来评估
}


int MaxMin::Max(int depth)
{
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
		val=Min(depth-1);
		UnMakeMoves();//撤销当前走法
		if (val>best)
		{
			/* code */
			best=val;
		}
	}
	return best;
}

int MaxMin::Min(int depth)
{
	int best=INFINITY;
	if (depth<=0)
	{
		/* code */
		return Evaluate();
	}
	GenerateLegalMoves();
	while(MovesLeft())//遍历所有着点
	{
		MakeNextMove();//实施着法
		val=Max(depth-1);
		UnMakeMoves();//撤销着法
		if(val<best)
		{
			best=val;
		}
	}
	return best;
}

//生成每一步有空位的点
int MaxMin::GenerateLegalMoves()
{
	int neighbors[];
	int nextNeighbors[];
	int flag=0;
	for(int i=0;i<15;i++)
	{
		for (int j = 0; j < 15; j++)
		{
			/* code */
			if(board[i][j]==0)
			{
				x[flag]=i;
				y[flag]=j;
				flag++;
			}
		}
	}
}

int MaxMin::MakeNextMove()
{
	
}


int MaxMin::UnMakeMoves()
{
	
}

int MaxMin::MovesLeft()
{
	
}