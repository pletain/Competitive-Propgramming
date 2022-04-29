#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int VISITED = 1;
const int UNVISITED = -1;

int AdjMatrix[26][26];
int dfs_num[26][26];
vector<int> unit;

void dfs(int r, int c)
{
    dfs_num[r][c] = VISITED;
    unit.back()++;
    if (AdjMatrix[r + 1][c] == 1 && dfs_num[r + 1][c] == UNVISITED)
    {
        dfs(r + 1, c);
    }
    if (AdjMatrix[r - 1][c] == 1 && dfs_num[r - 1][c] == UNVISITED)
    {
        dfs(r - 1, c);
    }
    if (AdjMatrix[r][c + 1] == 1 && dfs_num[r][c + 1] == UNVISITED)
    {
        dfs(r, c + 1);
    }
    if (AdjMatrix[r][c - 1] == 1 && dfs_num[r][c - 1] == UNVISITED)
    {
        dfs(r, c - 1);
    }
}

int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%1d", &AdjMatrix[i][j]);
            dfs_num[i][j] = UNVISITED;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (AdjMatrix[i][j] == 1 && dfs_num[i][j] == UNVISITED)
            {
                unit.push_back(0);
                dfs(i, j);
            }
        }
    }

    sort(unit.begin(), unit.end());
    cout << unit.size() << endl;
    for (int j = 0; j < (int)unit.size(); j++)
    {
        cout << unit[j] << endl;
    }
    return 0;
}