#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 1005
int w[N];
int d[N];
int map[N][N];
int sum[N];
int n;
int min=100000000;
bool record[N];


void dfs(int start,int mid,int num,int end)
{
	if(map[start][end]>0) return;
	if(mid==end)
	{
		map[start][end]=num;
		map[end][start]=num;	
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(mid!=i&&map[mid][i]>0&&record[mid]==0)
		{
			record[mid]=1;
			dfs(start,i,num+map[mid][i],end); 
			record[mid]=0;
		}
	}	
} 

bool visited[N];

bool istart()
{
	for(int i=1;i<=n;i++)
		if(sum[i]==0) return true;	
	return false;
}

bool isok()
{
	for(int i=1;i<=n;i++)
		if(sum[i]>d[i]) return false;
	return true;
}

void helper(int t,int now)
{
	if(!istart())
	{		
		if(isok()) 
		{
			if(min>now) min=now;
			return;
		}
	}
	for(int i=t;i<=n;i++)
	{
		if(!visited[i])
		{	
			visited[i]=1;
			int tmp[N];
			for(int j=1;j<=n;j++)
				tmp[j]=sum[j];
			for(int j=1;j<=n;j++)
			{				
				if(sum[j]!=-1)
				{
					if(sum[j]==0)
						sum[j]=map[i][j];
					else
						sum[j]=sum[j]<map[i][j]?sum[j]:map[i][j];
				}
			}
			sum[i]=-1;			
			helper(i+1,now+w[i]);
			for(int j=1;j<=n;j++)
				sum[j]=tmp[j];
			visited[i]=0;
		}
	}
}


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		min=100000000;
		memset(sum,0,sizeof(sum));
		memset(map,0,sizeof(map));
		memset(record,0,sizeof(record));
		memset(visited,0,sizeof(visited));
		for(int i=1;i<=n;i++)
			scanf("%d",&w[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&d[i]);
		int a,b,l;		
		for(int i=1;i<n;i++)
		{			
			scanf("%d%d%d",&a,&b,&l);
			map[a][b]=l;
			map[b][a]=l;
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				dfs(i,i,0,j);
		helper(1,0);
		printf("%d\n",min);
			
		
	}

    return 0;
}

