#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int bfs(P start, P dest, int l)
{
    static const int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
    static const int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

    queue<P> q;
    vector<vector<int>> dist(l, vector<int>(l, 987654321));
    q.push(start);
    dist[start.first][start.second] = 0;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (size_t i = 0; i < 8; ++i)
        {
            int nxt_y = y + dy[i];
            int nxt_x = x + dx[i];
            if (nxt_y < 0 || nxt_y >= l || nxt_x < 0 || nxt_x >= l)
                continue;

            if (dist[nxt_y][nxt_x] > dist[y][x] + 1)
            {
                q.push({nxt_y, nxt_x});
                dist[nxt_y][nxt_x] = dist[y][x] + 1;
            }
        }
    }

    return dist[dest.first][dest.second];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t T;
    cin >> T;
    for (size_t tc = 0; tc < T; ++tc)
    {
        int l;
        P start, dest;
        cin >> l >> start.second >> start.first >> dest.second >> dest.first;
        cout << bfs(start, dest, l) << '\n';
    }
}