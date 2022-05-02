#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
const int VISITED = 1;
const int UNVISITED = -1;

int main()
{
    int T, N, M, K, CNT;
    vi worm;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        CNT = 0;
        cin >> N >> M >> K;
        int AdjMatrix[N + 1][M + 1] = {
            0,
        };
        int dfs_num[N + 1][M + 1];

        for (int j = 0; j < K; j++)
        {
            int x, y;
            cin >> x >> y;
            AdjMatrix[x][y] = 1;
            dfs_num[x][y] = UNVISITED;
        }

        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (AdjMatrix[j][k] == 1 && dfs_num[j][k] == UNVISITED)
                {
                    CNT++;
                    dfs_num[j][k] = VISITED;
                    ii p = make_pair(j, k);
                    queue<ii> q; q.push(p);

                    while (!q.empty())
                    {
                        ii x = q.front();
                        q.pop();
                        if (AdjMatrix[x.first+1][x.second] == 1 && dfs_num[x.first+1][x.second] == UNVISITED)
                        {
                            dfs_num[x.first+1][x.second] = VISITED;
                            p = make_pair(x.first+1, x.second);
                            q.push(p);
                        }
                        if (AdjMatrix[x.first-1][x.second] == 1 && dfs_num[x.first-1][x.second] == UNVISITED)
                        {
                            dfs_num[x.first-1][x.second] = VISITED;
                            p = make_pair(x.first-1, x.second);
                            q.push(p);
                        }
                        if (AdjMatrix[x.first][x.second+1] == 1 && dfs_num[x.first][x.second+1] == UNVISITED)
                        {
                            dfs_num[x.first][x.second+1] = VISITED;
                            p = make_pair(x.first, x.second+1);
                            q.push(p);
                        }
                        if (AdjMatrix[x.first][x.second-1] == 1 && dfs_num[x.first][x.second-1] == UNVISITED)
                        {
                            dfs_num[x.first][x.second-1] = VISITED;
                            p = make_pair(x.first, x.second-1);
                            q.push(p);
                        }
                    }
                }
            }
        }
        worm.push_back(CNT);
    }
    for(int j=0; j<(int)worm.size(); j++){
        cout << worm[j] << endl;
    }
}