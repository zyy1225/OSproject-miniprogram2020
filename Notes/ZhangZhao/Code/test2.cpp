#include <iostream>
#include <vector>
#include <string>
//#include <algorithm>
using namespace std;

void dfs(vector<string>& t, int i, int j){
	if(i > 0){
		if(t[i - 1][j] == '#'){
			t[i - 1][j] = '.';
			dfs(t, i - 1, j);
		} 		
		if(j > 0 && t[i - 1][j - 1] == '#'){
			t[i - 1][j - 1] = '.';
			dfs(t, i - 1, j - 1);
		}			
	}
	if(j > 0){
		if(t[i][j - 1] == '#'){
			t[i][j - 1] = '.';
			dfs(t, i, j - 1);
		} 		
		if(i < t.size() - 1 && t[i + 1][j - 1] == '#'){
			t[i + 1][j - 1] = '.';
			dfs(t, i + 1, j - 1);
		}
	}
	if(i < t.size() - 1){
		if(t[i + 1][j] == '#'){
			t[i + 1][j] = '.';
			dfs(t, i + 1, j);
		} 		
		if(j < t[0].length() - 1 && t[i + 1][j + 1] == '#'){
			t[i + 1][j + 1] = '.';
			dfs(t, i + 1, j + 1);
		}			
	}
	if(j < t[0].length() - 1){
		if(t[i][j + 1] == '#'){
			t[i][j + 1] = '.';
			dfs(t, i, j + 1);
		} 		
		if(i > 0 && t[i - 1][j + 1] == '#'){
			t[i - 1][j + 1] = '.';
			dfs(t, i - 1, j + 1);
		}			
	}		
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<string> t(n, "");
	for(int i = 0; i < n; ++i)
		cin >> t[i];
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(t[i][j] == '#'){
				dfs(t, i, j);
				++ans;
			}
		}
	}
	printf("%d\n", ans);	
	return 0;
}
