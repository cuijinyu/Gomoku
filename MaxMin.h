#include"point.h"
class MaxMin
{
public:
	MaxMin(int d,int b[15][15],int c):depth(d),color(c)
	{};
	~MaxMin();
	int MinMax(int b[15][15],int depth);
	int Max(int depth,int alpha,int beta);
	int Max(int depth);//当极大极小值函数第一层搜索时的重载
	int Min(int depth,int alpha,int beta);
	int Min(int depth);//理由同上
	int GenerateLegalMoves();
	void MakeNextMove();
	void UnMakeMoves();
	bool MovesLeft();
	int SideToMove();
private:
	int val;
	int depth;
	int board[15][15];
	Point points[225];
	Point neighbors[225];
	int flag;
	int flagMove=0;//标志搜索位置的记录
	int tryOne;//尝试下子的记录
	int color;//电脑是什么颜色
	int ABcut=0;//记录AB剪枝数
};
