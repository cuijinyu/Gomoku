class MaxMin
{
public:
	MaxMin(int d,int b[][],int c):depth(d),board(b),color(c)
	{
	};
	~MaxMin();
	int MinMax(int board,int depth);
	int Max(int depth);
	int Min(int depth);
	int GenerateLegalMoves();
	void MakeNextMove();
	void UnMakeMoves();
	int MovesLeft();
	int SideToMove();
private:
	int val;
	int depth;
	int board[15][15];
	int x[225];
	int y[225];
	int flag;
	int flagMove=0;//标志搜索位置的记录
	int tryOne;//尝试下子的记录
	int color;//电脑是什么颜色
};
