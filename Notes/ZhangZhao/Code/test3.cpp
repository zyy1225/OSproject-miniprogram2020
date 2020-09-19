#include <iostream>
#include <vector>
#include <unordered_set>
//#include <string>
//#include <algorithm>
using namespace std;

int main(){
	int n, m;	
	scanf("%d %d", &n, &m);	
	while(m | n){
		unordered_set<int> s;
		s.insert(0);
		for(int i = 0; i < m; ++i){
			int k;	
			scanf("%d", &k);
			vector<int> num;
			bool flag = false;
			int tmp;
			for(int j = 0; j < k; ++j){				
				scanf("%d", &tmp);
				num.push_back(tmp);	
				if(!flag && s.find(tmp) != s.end()) flag = true;
			}
			if(flag){
				for(int j = 0; j < k; ++j)
					s.insert(num[j]);	
			}
			if(s.size() == n) break;
		}
		printf("%d\n", s.size());	
			
		scanf("%d %d", &n, &m);	
	}
	return 0;
}
