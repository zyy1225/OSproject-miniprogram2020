#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 110

int n,f,d;
int stu_f[N][N],stu_d[N][N];
bool record_f[N];
bool record_d[N];
int max;

void dfs(int t,int count)
{
	if(t>n)
	{
		if(count>max) max=count;
		return;
	}
	for(int i=1;i<=stu_f[t][0];i++)
		for(int j=1;j<=stu_d[t][0];j++)
		{
			if(!record_f[stu_f[t][i]]&&!record_d[stu_d[t][j]])
			{
				record_f[stu_f[t][i]]=1;
				record_d[stu_d[t][j]]=1;
				dfs(t+1,count+1);				
				record_f[stu_f[t][i]]=0;
				record_d[stu_d[t][j]]=0;
			}
		}
	dfs(t+1,count);		
}

int main()
{
	scanf("%d%d%d",&n,&f,&d);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&stu_f[i][0],&stu_d[i][0]);
		for(int j=1;j<=stu_f[i][0];j++)
			scanf("%d",&stu_f[i][j]);
		for(int j=1;j<=stu_d[i][0];j++)
			scanf("%d",&stu_d[i][j]);
	}
	dfs(1,0);
	printf("%d\n",max);

    return 0;
}

