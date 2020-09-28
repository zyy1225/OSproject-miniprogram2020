```c++
// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且有效的括号组合。

vector<string> ans;

void dfs(string path, int n, int LeftNum, int RightNum) {
    if (LeftNum > n || RightNum > n || LeftNum < RightNum)
        return;
    if (LeftNum == RightNum && LeftNum == n) {
        ans.push_back(path);
        return;
    }
    dfs(path + '(', n, LeftNum+1, RightNum);
    dfs(path + ')', n, LeftNum, RightNum+1);
}

vector<string> generateParenthesis(int n) {
    int LN = 0, RN = 0;
    dfs("", n, LN, RN);
    return ans;
}
```