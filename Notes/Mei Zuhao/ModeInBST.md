```c++
/*
 * 给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
 * 假定 BST 有如下定义：
 * 结点左子树中所含结点的值小于等于当前结点的值
 * 结点右子树中所含结点的值大于等于当前结点的值
 * 左子树和右子树都是二叉搜索树
 */

// curr=当前众数，count=当前数的出现次数，maxCount=众数次数
int curr, count, maxCount;
vector<int> ans;

// 中序遍历，所有元素都会连续重复出现
// update更新当前众数及次数
void update(int x) {
    if (curr == x)
        ++count;
    else {
        count = 1;
        curr = x;
    }
    if (count == maxCount) {
        ans.push_back(x);
    }
    else if (count > maxCount) {
        maxCount = count;
        ans = {x};
    }
}
vector<int> findMode(TreeNode* root) {
    TreeNode* now = root;
    // 中序遍历
    if (!now)
        return ans;
    if (now->left)
        findMode(now->left);
    update(now->val);
    if (now->right)
        findMode(now->right);
    return ans;
}
```