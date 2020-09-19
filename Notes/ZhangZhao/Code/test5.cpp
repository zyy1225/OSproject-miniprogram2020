#include <iostream>
#include <vector>
//#include <unordered_set>
//#include <string>
//#include <algorithm>
using namespace std;

int Max = 0;
void help(vector<vector<int>>& stu, vector<int>& FT, vector<int>& DT, int i, int curSum){
	if(i >= stu.size()) Max = max(Max, curSum);
	else{
		help(stu, FT, DT, i + 1, curSum);
		
		int f = stu[i][0], d = stu[i][1];
		int f1 = -1, f2 = -1;
		for(int k = 0; k < f; ++k){
			if(FT[stu[i][k + 2]] == 1){
				f1 = stu[i][k + 2];
				break;
			}			
		}

		if(f1 != -1){
			for(int k = 0; k < d; ++k){
				if(DT[stu[i][k + 2 + f]] == 0){
					f2 = stu[i][k + 2 + f];
					break;
				}
			}			
		}
		
		if(f2 != -1){
			for(int k = 0; k < f; ++k){
				if(FT[stu[i][k + 2]] == 1){
					FT[stu[i][k + 2]] = 0;
					for(int j = 0; j < d; ++j){
						if(DT[stu[i][j + 2 + f]] == 1){
							DT[stu[i][j + 2 + f]] = 0;
							help(stu, FT, DT, i + 1, curSum + 1);
							DT[stu[i][j + 2 + f]] = 1;							
						}
					}
					FT[stu[i][k + 2]] = 1;					
				}								
			}									
		}
	}
}

int main(){
	int N, F, D;	
	scanf("%d %d %d", &N, &F, &D);
	vector<int> FT(F, 1), DT(D, 1);
	vector<vector<int>>	stu(N);
	for(int i = 0; i < N; ++i){
		int f, d;
		scanf("%d %d", &f, &d);
		int sum = f + d;
		stu[i].push_back(f);
		stu[i].push_back(d);
		while(sum--){
			int tmp;
			scanf("%d", &tmp);
			stu[i].push_back(tmp);
		}			
	}
	help(stu, FT, DT, 0, 0);
	printf("%d\n", Max);
	return 0;
}
