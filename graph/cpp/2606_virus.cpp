#include<iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = -1;

vi AdjList[101];
vi d;
queue<int> q;
int cnt = 0;

void bfs() {
    d[1] = 0; q.push(1); 
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int j=0; j<(int)AdjList[u].size(); j++) {
            int v = AdjList[u][j];
            if(d[v] == INF) {
                cnt++;
                d[v] = d[u] +1;
                q.push(v);
            }
        }
    }
    
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int S, E;
        cin >> S >> E;
        AdjList[S].push_back(E);
        AdjList[E].push_back(S);
    }
    d.assign(N+1,INF);
    bfs();
    cout << cnt;

    return 0;
}