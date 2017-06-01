#ifndef __MAXMIN_H__
#define __MAXMIN_H__
class MaxMin
{
public:
	MaxMin(int d,int b[][])
	{
		depth=d;
		board=b;
	};
	~MaxMin();
	int MinMax(int board,int depth);
	int Max(int depth);
	int Min(int depth);
	int GenerateLegalMoves();
	int MakeNextMove();
	int UnMakeMoves();
	int MovesLeft();
private:
	int depth;
	int board[15][15];
	int x[225];
	int y[225];
};
#endif