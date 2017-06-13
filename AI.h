#ifndef AI_H
#define AI_H
/*
    AI评估函数：
		1：对棋盘进行遍历对每个点进行检索（即将每个点周围情况用四个函数HorJudge，VerJudge，SprJudge，BacJudge进行存储）
		2：将存储好的各点的情况与评估函数按分值大小顺序进行匹配
		3：用上述方法对己方和对方分别评估，并存储在两个数组中，取较大值作为该点的分数
		4：最后对所有点分数进行比较，取值最大的点作为落子点，将值最大的点存储在数组中 
*/

 
class AI{
public:
	a[15][15];		//棋盘 
	const int MSide;	//代表我方棋子的颜色
	int i=0,j=0;   //i代表纵轴，j代表横轴
	
	void HorJudge(int ay,int ax,int side);     //横轴判断连子的个数 ay代表纵轴，ax代表横轴，num代表个数 chessboard[1]
	void VerJudge(int ay,int ax,int side);     //纵轴判断连子的个数 chessboard[2]
	void SprJudge(int ay,int ax,int side);     //'/'斜杠判断连子的个数 chessboard[3]
	void BacJudge(int ay,int ax,int side);     //'\'斜杠判断连子的个数 chessboard[4]
	
	bool Five(int i,int j,int side); 	//100
	bool A_four(int i,int j,int side);	//90
	bool Double_D_four(int i,int j,int side);	//90
	bool D_four_A_three(int i,int j,int side);	//90
	bool Double_three(int i,int j,int side);	//80
	bool D_three_A_three(int i,int j,int side);	//70
	bool D_four(int i,int j,int side);	//60
	bool A_three(int i,int j,int side);	//50
	bool Double_A_two(int i,int j,int side);	//40
	bool D_three(int i,int j,int side);	//30
	bool A_two(int i,int j,int side);		//20
	bool D_two(int i,int j,int side);		//10
	bool One(int i,int j,int side);	//0
	
	int ChessBoard[4][2]={{0,0}};		//表示四路的状态 第一个为两边情况 第二个为连子个数 
};
/*
		
*/
void AI::HorJudge(int ay,int ax,int side)   //(ay,ax)表示当前要检索的点坐标，side表示白或者黑子，即本方 
{
	a[ay][ax]=side;
	int i=ax;
	while(a[ay][i]==side&&i>=0)           //左 
	{
		ChessBoard[1][1]++; 
		i--;			
	}
	if(a[ay][i]!=0||i<0)
		ChessBoard[1][0]+=3;
	else
	{
		while(a[ay][i]==side&&i>=0)
		{
			ChessBoard[1][1]++; 
			i--;			
		}
		if(a[ay][i]!=0||i<0)
			ChessBoard[1][0]++;
	}
		
	i=ax+1;								//右 
	while(a[ay][i]==side&&i<15)
	{
		ChessBoard[1][1]++;
		i++;
	}
	if(a[ay][i]!=0||i>=15)
		ChessBoard[1][0]+=3;
	else
	{
		while(a[ay][i]==side&&i<15)
		{
			ChessBoard[1][1]++;
			i++;
		}
		if(a[ay][i]!=0||i>=15)
			ChessBoard[1][0]++;
	}
	
	a[ay][ax]=0;          //当前点置零 
}

void AI::VerJudge(int ay,int ax,int side)
{
	a[ay][ax]=side;
	int i=ay;
	
	while(a[i][ax]==side&&i>=0)
	{
		ChessBoard[2][1]++;
		i--;	
	}
	if(a[i][ax]!=0||i<0)
		ChessBoard[2][0]+=3;
	else
	{
		while(a[i][ax]==side&&i>=0)
		{
			ChessBoard[2][1]++;
			i--;	
		}
		if(a[i][ax]!=0||i<0)
			ChessBoard[2][0]++;
	}
	
	i=ay+1;
	while(a[i][ax]==side&&i<15)
	{
		ChessBoard[2][1]++;
		i++;
	}
	if(a[i][ax]!=0||i>=15)
		ChessBoard[2][0]+=3;
	else
	{
		while(a[i][ax]==side&&i<15)
		{
			ChessBoard[2][1]++;
			i++;
		}
		if(a[i][ax]!=0||i>=15)
			ChessBoard[2][0]++;
	}
		
	a[ay][ax]=0;
}

void AI::SprJudge(int ay,int ax,int side)
{
	a[ay][ax]=side;
	int i=ay,j=ax;
	while(a[i][j]==side&&i>=0&&j<15)
	{
		ChessBoard[3][1]++;
		i--;
		j++;
	} 
	if(a[i][j]!=0||i<0||j>=15)
		ChessBoard[3][0]+=3;
	else
	{
		while(a[i][j]==side&&i>=0&&j<15)
		{
			ChessBoard[3][1]++;
			i--;
			j++;
		} 
		if(a[i][j]!=0||i<0||j>=15)
			ChessBoard[3][0]++;
	}
	
	i=ay+1;
	j=ax-1;
	while(a[i][j]==side&&i<15&&j>=0)
	{
		ChessBoard[3][1]++;
		i++;
		j--;
	}
	if(a[i][j]!=0||i>=15||j<0)
		ChessBoard[3][0]+=3;
	else
	{
		while(a[i][j]==side&&i<15&&j>=0)
		{
			ChessBoard[3][1]++;
			i++;
			j--;
		}
		if(a[i][j]!=0||i>=15||j<0)
			ChessBoard[3][0]++;
	}
		
	a[ay][ax]=0;
}

void AI::BacJudge(int ay,int ax,int side)
{
	a[ay][ax]=side;
	int i=ay;
	int j=ax;
	while(a[i][j]==side&&i>=0&&j>=0)
	{
		ChessBoard[4][1]++;
		i--;
		j--;
	}
	if(a[i][j]!=0||i<0||j<0)
		ChessBoard[4][0]+=3;
	else
	{
		while(a[i][j]==side&&i>=0&&j>=0)
		{
			ChessBoard[4][1]++;
			i--;
			j--;
		}
		if(a[i][j]!=0||i<0||j<0)
			ChessBoard[4][0]++;
	}
		
	i=ay++;
	j=ax++;
	while(a[i][j]==side&&i<15&&j<15)
	{
		ChessBoard[4][1]++;
		i++;
		j++;
	}
	if(a[i][j]!=0||i>=15||j>=15)
		ChessBoard[4][0]+=3;
	else
	{
		while(a[i][j]==side&&i<15&&j<15)
		{
			ChessBoard[4][1]++;
			i++;
			j++;
		}
		if(a[i][j]!=0||i>=15||j>=15)
			ChessBoard[4][0]++;
	}
	
	a[ay][ax]=0;
} 

bool AI::Five(int i,int j,int side)
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<2;j++)
		{
			if(ChessBoard[i][1]==5)
				return true;
			else
				return false;
		}
	}
}

bool AI::A_four(int i,int j,int side)
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<2;j++)
		{
			if(ChessBoard[i][1]==4&&ChessBoard[i][0]<=2)
				return true;
			else
				return false;
		}
	}
}

bool AI::Double_D_four(int i,int j,int side)
{
	int i,j;
	int number=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<2;j++)
		{
			if(ChessBoard[i][1]==4&&(ChessBoard[i][0]==3||ChessBoard[i][0]==4))
				number++;
		}
	}
	
	if(number>=2)
		return true;
	else
		return false;
}

bool AI::D_four_A_three(int i,int j,int side)
{
	int i,j;
	int number=0;
	for(i=0;i<4;i++)
	{
		if((ChessBoard[i][1]==4&&(ChessBoard[i][0]==3||ChessBoard[i][0]==4))||(ChessBoard[i][1]==3&&ChessBoard[i][0]<=2))
			number++;
	}
	
	if(number>=2)
		return true;
	else
		return false;
}

bool AI::Double_three(int i,int j,int side)
{
	int i;
	int number=0;
	for(i=0;i<4;i++)
	{
		if(ChessBoard[i][1]==3&&ChessBoard[i][0]<=2)
			number++;
	}
	if(number>=2)
		return true;
	else
		return false;
}

bool AI::D_three_A_three(int i,int j,int side)
{
	int i;
	int number=0;
	for(i=0;i<4;i++)
	{
		if((ChessBoard[i][1]==3&&(ChessBoard[i][0]==3||ChessBoard[i][0]==4))||(ChessBoard[i][1]==3&&ChessBoard[i][0]<=2))
			number++;
	}
	if(number>=2)
		return true;
	else 
		return false;
}

bool AI::D_four(int i,int j,int side)
{
	int i;
	for(i=0;i<4;i++)
	{
		if(ChessBoard[i][1]==4&&(ChessBoard[i][0]==3||ChessBoard[i][0]==4))
			return true;
		else
			return false;	
	}
}

bool AI::A_three(int i,int j,int side)
{
	int i;
	for(i=0;i<4;i++)
	{
		if(ChessBoard[i][1]==3&&ChessBoard[i][0]<=2)
			return true;
		else
			return false;
	}
}

bool AI::Double_A_two(int i,int j,int side)
{
	int i;
	int number=0;
	for(i=0;i<4;i++)
	{
		if(ChessBoard[i][1]==2&&ChessBoard[i][0]<=2)
			number++;
	}
	if(number>=2)
		return true;
	else
		return false;
}

bool AI::D_three(int i,int j,int side)
{
	int i;
	for(i=0;i<4;i++)
	{
		if(ChessBoard[i][1]==3&&(ChessBoard[i][0]==3||ChessBoard[i][0]==4))
			return true;
		else 
			return false;
	}
}

bool AI::A_two(int i,int j,int side)
{
	int i;
	for(i=0;i<4;i++)
	{
		if(ChessBoard[i][1]==2&&ChessBoard[i][0]<=2)
			return true;
		else
			return false;
	}
}

bool AI::D_two(int i,int j,int side)
{
	int i;
	for(i=0;i<4;i++)
	{
		if(ChessBoard[i][1]==2&&(ChessBoard[i][0]==3||ChessBoard[i][0]==4))
			return true;
		else
			return false;
	}
}

bool AI::One(int i,int j,int side)
{
	int i;
	for(i=0;i<4;i++)
	{
		if(ChessBoard[i][1]==1)
			return true;
		else
			return false;
	}
}

void judge()  //评估函数 
{
	int b[15][15]={{-1}};
	int c[15][15]={{-1}};
	int temp[15][15]={{-1}};
	int max=0;
	int finalP[255]={0};
	
    int i,j;
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
        	if(a[i][j]==0)
        	{
	        	b[i][j]=a[i][j];
	        	c[i][j]=a[i][j];
	        	
	        	AI.HorJudge(i,j,MSide);
	        	AI.VerJudge(i,j,MSide);
	        	AI.SprJudge(i,j,MSide);
	        	AI.BacJudge(i,j,MSide);
	        	
	        	if(AI.Five(i,j,MSide))       //己方价值评估 
					b[i][j]=101;
				else
				if(AI.A_four(i,j,MSide))
					b[i][j]=91;
				else
				if(AI.Double_D_four(i,j,MSide))
					b[i][j]=91;
				else
				if(AI.D_four_A_three(i,j,MSide))
					b[i][j]=91;
				else
				if(AI.Double_three(i,j,MSide))
					b[i][j]=81;
				else
				if(AI.D_three_A_three(i,j,MSide))
					b[i][j]=71;
				else
				if(AI.D_four(i,j,MSide))
					b[i][j]=61;
				else
				if(AI.A_three(i,j,MSide))
					b[i][j]=51;
				else
				if(AI.Double_A_two(i,j,MSide))
					b[i][j]=41;
				else
				if(AI.D_three(i,j,MSide))
					b[i][j]=31;
				else
				if(AI.A_two(i,j,MSide))
					b[i][j]=21;
				else
				if(AI.D_two(i,j,MSide))
					b[i][j]=11;
				else
				if(AI.One(i,j,MSide))
					b[i][j]=1;
					
				memset(a,0,sizeof(a));
										
				AI.HorJudge(i,j,-MSide);
	        	AI.VerJudge(i,j,-MSide);
	        	AI.SprJudge(i,j,-MSide);
	        	AI.BacJudge(i,j,-MSide);	
					
				if(AI.Five(i,j,-MSide)) 	//对方价值评估 
					c[i][j]=100;
				else
				if(AI.A_four(i,j,-MSide))
					c[i][j]=90;
				else
				if(AI.Double_D_four(i,j,-MSide))
					c[i][j]=90;
				else
				if(AI.D_four_A_three(i,j,-MSide))
					c[i][j]=90;
				else
				if(AI.Double_three(i,j,-MSide))
					c[i][j]=80;
				else
				if(AI.D_three_A_three(i,j,-MSide))
					c[i][j]=70;
				else
				if(AI.D_four(i,j,-MSide))
					c[i][j]=60;
				else
				if(AI.A_three(i,j,-MSide))
					c[i][j]=50;
				else
				if(AI.Double_A_two(i,j,-MSide))
					c[i][j]=40;
				else
				if(AI.D_three(i,j,-MSide))
					c[i][j]=30;
				else
				if(AI.A_two(i,j,-MSide))
					c[i][j]=20;
				else
				if(AI.D_two(i,j,-MSide))
					c[i][j]=10;
				else
				if(AI.One(i,j,-MSide))
					c[i][j]=0;	
					
				memset(a,0,sizeof(a));
				
					
				temp[i][j]=a[i][j]>b[i][j]?a[i][j]:b[i][j];
			}
        }
    }
    
    
    for(i=0;i<15;i++)
    {
    	for(j=0;j<15;j++)
    	{  		
    		if(temp[i][j]>max)
    		{
				max=[i][j];
    		}
    	}
    }
    
    int t=0;
    int xx=0;
    int yy=0;
    for(i=0;i<15;i++)
    {
    	for(j=0;j<15;j++)
    	{
    		if(temp[i][j]==max)
    		{
    			finalP[t]=i*j;       //将分数最高的点赋值1，作为传入值
    			t++;
    		}
    	}
    }
    if(max==0)
    {
    	a[7][7]=MSide;
    }
    else
    {
    	xx=finalP[0]/i;
    	yy=finalP[0]/j;
    	a[xx][yy]=MSide;
    }
    
    return 0;
}

