```c++
/*
 * 给定一个包括n个整数的数组nums和一个目标值target。
 * 找出nums中的三个整数，使得它们的和与target最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 */

int threeSumClosest(vector<int>& nums, int target) {
    int minDiff, left, right, ans, sum;
    sort(nums.begin(), nums.end()); // 排序
    minDiff = abs(nums[0] + nums[1] + nums[2] - target); // 保存当前最小差值
    for (int i = 0; i < nums.size(); ++i) { // 双指针，遍历nums[i]为首元素的三元组
        left = i+1;
        right = nums.size()-1;
        while (left < right) {
            sum = nums[i] + nums[left] + nums[right];
            if (abs(sum - target) <= minDiff) { // 找到了新的最小差值
                ans = sum;
                minDiff = abs(sum - target);
            }
            if (sum < target) {
                ++left;
            }
            else if (sum > target) {
                --right;
            }
            else
                return target;
        }
    }
    return ans;
}
```

