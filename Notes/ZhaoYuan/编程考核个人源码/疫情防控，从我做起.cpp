#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 30010
int n,m;
int pre[N];

int find(int root)
{
	int son=root;
	while(root!=pre[root])
	{
		root=pre[root];
	}
	while(son!=root)
	{
		int tmp=pre[son];
		pre[son]=root;
		son=tmp;
	}
	return root;
} 
int join(int root1,int root2)
{
	int x=find(root1);
	int y=find(root2);
	if(x!=y)
	{
		pre[x]=y;
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	while(!(n==0&&m==0))
	{			
		for(int i=0;i<n;i++) pre[i]=i;
		for(int i=0;i<m;i++)
		{
			int k;
			int root,tmp;
			scanf("%d",&k);
			scanf("%d",&root);
			for(int i=1;i<k;i++)
			{
				scanf("%d",&tmp);
				join(root,tmp);
			}			
		}
		int count=0;
		for(int i=0;i<n;i++)
		{
			int a=find(i);
			if(pre[0]==a)
				count++;
		}
		printf("%d\n",count);
		scanf("%d%d",&n,&m);
	}
	
    return 0;
}

