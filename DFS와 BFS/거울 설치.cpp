#include <deque>
#include <iostream>
using namespace std;

const int MAX = 50;
const int INF = 251;
typedef pair<int, int> P;

int N;
char house[MAX + 1][MAX + 1];
int dist[4][MAX + 1][MAX + 1];

int bfs(P start, P dest)
{
    const int dy[] = {-1, 0, 1, 0};
    const int dx[] = {0, 1, 0, -1};

    int ret = INF;
    deque<pair<P, int>> d;

    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < N; j++)
            for (size_t k = 0; k < N; k++)
                dist[i][j][k] = INF;

    for (size_t i = 0; i < 4; i++)
    {
        P nxt = {start.first + dy[i], start.second + dx[i]};
        if (nxt.first < 0 || nxt.first >= N || nxt.second < 0 || nxt.second >= N)
            continue;
        if (house[nxt.first][nxt.second] == '*')
            continue;

        dist[i][nxt.first][nxt.second] = 0;
        d.push_back(make_pair(nxt, i));
    }

    while (!d.empty())
    {
        P cur = d.front().first;
        int dir = d.front().second;
        d.pop_front();

        for (size_t i = 0; i < 4; i++)
        {
            P nxt = {cur.first + dy[i], cur.second + dx[i]};
            if (nxt.first < 0 || nxt.first >= N || nxt.second < 0 || nxt.second >= N)
                continue;
            if (house[nxt.first][nxt.second] == '*')
                continue;

            if (i == dir)
            {
                if (dist[i][nxt.first][nxt.second] > dist[dir][cur.first][cur.second])
                {
                    dist[i][nxt.first][nxt.second] = dist[dir][cur.first][cur.second];
                    d.push_front(make_pair(nxt, i));
                }
            }
            if (house[cur.first][cur.second] == '!' && (i == (dir + 1) % 4 || i == (dir + 3) % 4))
            {
                if (dist[i][nxt.first][nxt.second] > dist[dir][cur.first][cur.second] + 1)
                {
                    dist[i][nxt.first][nxt.second] = dist[dir][cur.first][cur.second] + 1;
                    d.push_back(make_pair(nxt, i));
                }
            }
        }
    }

    for (size_t i = 0; i < 4; i++)
        ret = min(ret, dist[i][dest.first][dest.second]);

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    P start = {-1, -1}, dest = {-1, -1};
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> house[i];
        for (size_t j = 0; j < N; j++)
        {
            if (house[i][j] == '#')
                (start.first == -1) ? start = {i, j} : dest = {i, j};
        }
    }

    cout << bfs(start, dest) << '\n';
}