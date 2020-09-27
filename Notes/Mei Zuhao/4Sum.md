```c++
/* 
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？
 * 找出所有满足条件且不重复的四元组。
 * 注意：答案中不可以包含重复的四元组。
 */

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int size = nums.size();
    vector<vector<int>> ans;
    if (size < 4)
        return ans;
    for (int a = 0; a < size-3; ++a) {
        if (a > 0 && nums[a] == nums[a-1])
            continue;
        for (int b = a+1; b < size-2; ++b) {
            int c = b+1, d = size-1;
            if (b > a+1 && nums[b] == nums[b-1])
                continue;
            while (c < d) {
                vector<int> vec;
                int sum = nums[a] + nums[b] + nums[c] + nums[d];
                if (sum < target)
                    ++c;
                else if (sum > target)
                    --d;
                else {
                    vec = {nums[a], nums[b], nums[c], nums[d]};
                    ans.push_back(vec);
                    while (c < d && nums[c] == nums[c+1])
                        ++c;
                    while (c < d && nums[d] == nums[d-1])
                        --d;
                    ++c;
                    --d;
                }
            }
        }
    }
    return ans;
}
```

