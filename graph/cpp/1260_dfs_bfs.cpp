#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
const int VISITED = 1;
const int UNVISITED = -1;

vi dfs_num;
vi d;
queue<int> q;
vii AdjList[1001];



void dfs(int u) {
    dfs_num[u] = VISITED;
    cout << u << " ";
    for (int j=0; j < (int)AdjList[u].size(); j++ ) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == UNVISITED) {
            dfs(v.first);
        }
    }
}

void bfs(int s) {
    d[s] = 0; q.push(s); 

    while(!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            if (d[v.first] == UNVISITED) {
                d[v.first] = d[u] + 1;
                q.push(v.first);
            }
        }
    }
}

int main() {
    int N, M, V;
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++) {
        int S, E; ii p1, p2;
        cin >> S >> E;
        p1.first = S;
        AdjList[E].push_back(p1);
        p2.first = E;
        AdjList[S].push_back(p2);
    }

    for (int j=1; j<=N; j++)
        sort(AdjList[j].begin(), AdjList[j].end());

    dfs_num.assign(N+1,UNVISITED);
    dfs(V);
    cout << endl;

    d.assign(N+1,UNVISITED);
    bfs(V);
        
    return 0;
}