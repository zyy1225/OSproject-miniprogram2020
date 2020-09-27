```c++
// 给定n个整数的序列，求这个序列的任意连续子序列的最大和

// 暴力解法，时间复杂度 O(N^2)
#include <iostream>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        if (n == 0)
            break;
        int nums[n];
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        int max = nums[0];
        for (int i = 0; i < n; ++i) { // 遍历nums[i]
            int curr_max = nums[i], curr = nums[i];
            for (int j = i + 1; j < n; ++j) { // 遍历nums[i]其后的连续子序列
                curr += nums[j];
                curr_max = curr > curr_max ? curr : curr_max; 
                // curr_max保存nums[i]为第一个值的连续子序列的最大和
            }
            max = curr_max > max ? curr_max : max;
        }
        cout << max << endl;
    }
}

// 动态规划解法，时间复杂度O(N)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0)
            break;
        int nums[n], dp[n];
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        dp[0] = nums[0]; // 初始状态
        for (int i = 1; i < n; i++) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]); // 状态转移方程
        }
        sort(dp, dp + n); // 对dp内的元素进行排序
        cout << dp[n - 1] << endl; // 输出最大值
    }
}
```


