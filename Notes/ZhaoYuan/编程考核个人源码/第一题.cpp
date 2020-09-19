#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 10005

int num[N];

int main()
{
	int n;
	scanf("%d",&n);
	while(n>0)
	{
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
		int tmp=0,max=-100000;
		for(int i=0;i<n;i++)
		{
			tmp=0;
			for(int j=i;j<n;j++)
			{
				tmp+=num[j];
				if(tmp>max) max=tmp;				
			}
		}		
		printf("%d\n",max);	
		scanf("%d",&n);
	} 

    return 0;
}

