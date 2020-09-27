```c++
/*
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？
 * 请你找出所有满足条件且不重复的三元组。
 * 注意：答案中不可以包含重复的三元组。
 */

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    if (nums.empty() || nums.size() < 3)
        return ans;
    sort(nums.begin(), nums.end()); // 先排序
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0) // 排序后，如果元素nums[i]>0，后面的都不满足
            break;
        if (i > 0 && nums[i] == nums[i-1]) // 避免重复计算相同元素
            continue;
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            vector<int> triplet;
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                triplet = {nums[i], nums[left], nums[right]};
                while (left < right && nums[left] == nums[left+1]) // 去重
                    ++left;
                while (left < right && nums[right] == nums[right-1]) // 去重
                    --right;
                ++left;
                --right;
            }
            else if (sum < 0)
                ++left;
            else
                --right;
            if (!triplet.empty())
                ans.push_back(triplet);
        }
    }
    return ans;
}
```

