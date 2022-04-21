#include<iostream>
#include<utility>
#include<vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vi dfs_num;
vector<pair<int,int> > vertex[200];

void dfs(int u) {
    dfs_num[u] = VISITED;
    for ( int j=0; j < (int)AdjList[u].size(); j++ ) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == UNVISITED)
            dfs(v.first);
    }
}