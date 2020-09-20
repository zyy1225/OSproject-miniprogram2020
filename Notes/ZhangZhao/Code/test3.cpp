#include <iostream>
//#include <vector>
//#include <unordered_set>
//#include <string>
//#include <algorithm>
using namespace std;

#define maxn 33000
int pre[maxn], num[maxn];	//i的根结点为pre[i], i的子图中包含num[i]个节点。 
int a[maxn];
void init(int n){
	for(int i = 0; i < n; ++i){
		pre[i] = i;
		num[i] = 1;
	}
}
int find(int x){
	if(x == pre[x])
		return x;
	
	pre[x] = find(pre[x]);	//递归地查找当前连通图的根节点 
	return pre[x];
}
void join(int x, int y){
	int px = find(x), py = find(y);
	if(px != py){
		pre[px] = py;	//连接两个子图 
		num[py] += num[px];	//汇总两个子图的节点 
	}
}

int main(){
	int n, m;		
	while(scanf("%d %d", &n, &m), m || n){
		init(n);
		for(int i = 0; i < m; ++i){
			int k;	
			scanf("%d", &k);
			for(int j = 0; j < k; ++j)			
				scanf("%d", &a[j]);
			for(int j = 0; j < k - 1; ++j)			
				join(a[j], a[j + 1]);			
		}
		int root = find(0);
		printf("%d\n", num[root]);		
	}
	return 0;
}
