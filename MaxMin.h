class MaxMin
{
public:
	MaxMin(int d,int b[15][15],int c):depth(d),color(c)
	{
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				board[i][j] = b[i][j];
			}
		}
	};
	~MaxMin();
	int Evaluate();
	int MinMax(int depth);
	int Max(int depth,int alpha,int beta);
	int Min(int depth,int alpha,int beta);
	int GenerateLegalMoves();
	void MakeNextMove();
	void UnMakeMoves();
	bool MovesLeft();
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
