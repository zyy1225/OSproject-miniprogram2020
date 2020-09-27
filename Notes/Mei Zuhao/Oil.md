```c++
/*
 * 我国在某内陆地区进行石油探测, 探测的时候以方格的形式进行, 每个方格代表一个探测区域, 如果一个区域探测到石油则该区域为一块油田, 标记为#, 否则标记为.
 * 如果一个油田在8个方向上的相邻方格上也存在油田, 则这两个油田相邻, 所有相邻的油田构成一个油矿, 现在想在每个油矿处打一个油井, 请你写一个算法计算出总共需要打多少个油井.
 * 输入的第一行为两个整数 n (n in [1,100]) 和 m (m in [1,100])
 * 接下来 n 行, 每行有 m 个字符, 表示所有的探测区域, 每个字符只可能是 `#` 或 `.`, 字符之间没有空格.
 * 输出单独的一行, 即需要打的油井个数
 */

#include <iostream>
using namespace std;

#define maxn 103

int m, n;
char oil[maxn][maxn];

int dir[10][2] = {{-1, -1},
                  {-1, 0},
                  {-1, 1},
                  {0, -1},
                  {0, 1},
                  {1, 0},
                  {1, -1},
                  {1, 1}};

void dfs(int x, int y) {
    /*
     * 深度优先搜索
     * dfs的功能是将一个油矿中所有油田标记为.
     */
    oil[x][y] = '.';
    for (int i = 0; i < 8; ++i) {
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if (dx > n || dx < 1 || dy > m || dy < 1)
            continue;
        if (oil[dx][dy] == '.')
            continue;
        dfs(dx, dy); // oil[dx][dy]是油田
    }
}

int main() {
    int count = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            char c;
            cin >> c;
            oil[i][j] = c;
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (oil[i][j] == '#') {
                // oil[i][j]是新油田，将其所在的油矿全部改成.
                ++count;
                dfs(i, j);
            }
        }
    cout << count << endl;
 }
```


