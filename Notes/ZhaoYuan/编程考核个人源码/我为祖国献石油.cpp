#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 110
char map[N][N];
bool record[N][N];
int dir[8][2]={{0,1},{1,0},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
int n,m;

void dfs(int x,int y)
{
	for(int i=0;i<8;i++)
	{
		int newx=x+dir[i][0];
		int newy=y+dir[i][1];
		if(newx>=0&&newx<n&&newy>=0&&newy<m&&map[newx][newy]=='#'&&!record[newx][newy])
		{
			record[newx][newy]=1;
			dfs(newx,newy);
		}
	}
} 
int main()
{
	int count=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",map[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(map[i][j]=='#'&&!record[i][j])
			{
				dfs(i,j);
				count++;
			}
		}
	printf("%d\n",count);
    return 0;
}

