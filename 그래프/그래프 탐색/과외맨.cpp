#include <deque>
#include <iostream>
#include <stack>
using namespace std;
typedef pair<int, int> P;

const int INF = 987654321;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int N, num[1001][1001], tile[1001][1001], dist[1001][1001];
P pre[1001][1001];

P bfs()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= 2 * N; j++)
        {
            dist[i][j] = INF;
            pre[i][j] = {-1, -1};
        }
    }

    deque<P> d;
    d.push_back({1, 1});
    dist[1][1] = 1;

    while (!d.empty())
    {
        int y = d.front().first;
        int x = d.front().second;
        d.pop_front();

        for (size_t i = 0; i < 4; i++)
        {
            int nxt_y = y + dy[i];
            int nxt_x = x + dx[i];
            if (nxt_y <= 0 || nxt_y > N || nxt_x <= 0 || nxt_x > 2 * N)
                continue;
            if (tile[nxt_y][nxt_x] == 0)
                continue;
            if (tile[y][x] != tile[nxt_y][nxt_x] && num[y][x] != num[nxt_y][nxt_x])
                continue;

            int w = (tile[y][x] == tile[nxt_y][nxt_x]) ? 0 : 1;
            if (dist[nxt_y][nxt_x] > dist[y][x] + w)
            {
                (w == 0) ? d.push_front({nxt_y, nxt_x}) : d.push_back({nxt_y, nxt_x});
                dist[nxt_y][nxt_x] = dist[y][x] + w;
                pre[nxt_y][nxt_x] = {y, x};
            }
        }
    }

    for (int i = N; i >= 1; i--)
        for (int j = (i % 2 == 1 ? 2 * N : 2 * N - 1); j >= (i % 2 == 1 ? 1 : 2); j--)
            if (dist[i][j] != INF)
                return {i, j};

    return {-1, -1}; // error
}

void print_route(P cur)
{
    cout << dist[cur.first][cur.second] << '\n';

    stack<int> s;
    while (cur.first != -1)
    {
        if (s.empty() || s.top() != tile[cur.first][cur.second])
            s.push(tile[cur.first][cur.second]);
        cur = pre[cur.first][cur.second];
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cur_tile = 0;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = (i % 2 == 1 ? 1 : 2); j <= (i % 2 == 1 ? 2 * N : 2 * N - 1); j++)
        {
            cin >> num[i][j];
            tile[i][j] = cur_tile++ / 2 + 1;
        }
    }

    print_route(bfs());
}