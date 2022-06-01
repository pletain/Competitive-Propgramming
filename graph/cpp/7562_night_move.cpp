#include <iostream>
#include <queue>
#include <utility>
#define X first
#define Y second
using namespace std;

typedef pair<int, int> ii;
queue<ii> q;

const int UNVISITED = -1;
int dist[305][305];
int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[] = {-1, -2, -2, -1, 1, 2, 2, 1};

int main()
{
    int T, L;
    int x, y, endX, endY;
    ii start, end;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> L;
        for (int j = 0; j < L; j++)
        {
            for (int k = 0; k < L; k++)
            {
                dist[j][k] = 0;
            }
        }

        cin >> x >> y;
        cin >> endX >> endY;

        start = make_pair(x, y);
        end = make_pair(endX, endY);
        
        if (start == end)
            dist[endX][endY] = 0;
        else
        {
            q.push(start);
            while (!q.empty())
            {
                ii cur = q.front();
                ii next;
                q.pop();

                for (int dir = 0; dir < 8; dir++)
                {
                    int r = cur.X + dr[dir];
                    int c = cur.Y + dc[dir];

                    if (r >= 0 && r < L && c >= 0 && c < L && dist[r][c] == 0)
                    {
                        next = make_pair(r, c);
                        q.push(next);
                        dist[next.X][next.Y] = dist[cur.X][cur.Y] + 1;
                    }
                }
            }
        }

        cout << dist[endX][endY] << endl;
    }
}