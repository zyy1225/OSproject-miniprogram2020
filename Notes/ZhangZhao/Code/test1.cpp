#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	while(n > 0){
		//vector<int> num(n, 0);
		int sum = 0, Max = INT_MIN;
		for(int i = 0; i < n; ++i){
			int tmp;
			cin >> tmp;
			if(sum >= 0) sum += tmp;
			else sum = tmp;
			Max = max(Max, sum);
		}
		printf("%d\n", Max);	
		scanf("%d", &n);
	}
	return 0;
}
