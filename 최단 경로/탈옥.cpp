#include <deque>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX = 100;
const int INF = 100000;
typedef pair<int, int> P;

int h, w;
char prison[MAX + 2][MAX + 2];
int dist[3][MAX + 2][MAX + 2];

void bfs(P start, int idx)
{
    static int dx[4] = {1, -1, 0, 0};
    static int dy[4] = {0, 0, 1, -1};

    for (size_t i = 0; i <= h + 1; i++)
        for (size_t j = 0; j <= w + 1; j++)
            dist[idx][i][j] = INF;

    deque<P> d;
    d.push_back(start);
    dist[idx][start.first][start.second] = 0;

    while (!d.empty())
    {
        P cur = d.front();
        d.pop_front();

        for (size_t i = 0; i < 4; i++)
        {
            P nxt = {cur.first + dy[i], cur.second + dx[i]};
            if (nxt.first < 0 || nxt.first > h + 1 || nxt.second < 0 || nxt.second > w + 1)
                continue;
            if (prison[nxt.first][nxt.second] == '*')
                continue;

            int weight = (prison[nxt.first][nxt.second] == '#');
            if (dist[idx][nxt.first][nxt.second] > dist[idx][cur.first][cur.second] + weight)
            {
                dist[idx][nxt.first][nxt.second] = dist[idx][cur.first][cur.second] + weight;
                (weight == 0) ? d.push_front(nxt) : d.push_back(nxt);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t T;
    cin >> T;
    for (size_t tc = 0; tc < T; tc++)
    {
        P a = {-1, -1}, b = {-1, -1};
        cin >> h >> w;

        for (size_t i = 1; i <= h; i++)
        {
            string buffer;
            cin >> buffer;
            buffer = '.' + buffer + '.';

            for (size_t j = 0; j <= w + 1; j++)
            {
                prison[i][j] = buffer[j];
                if (prison[i][j] == '$')
                    (a.first == -1) ? a = {i, j} : b = {i, j};
            }
        }

        for (size_t j = 0; j <= w + 1; j++)
            prison[0][j] = prison[h + 1][j] = '.';

        bfs(P(0, 0), 0);
        bfs(a, 1);
        bfs(b, 2);

        int ret = INT32_MAX;
        for (size_t i = 0; i <= h + 1; i++)
        {
            for (size_t j = 0; j <= w + 1; j++)
            {
                if (dist[0][i][j] == INF)
                    continue;

                int cnt = dist[0][i][j] + dist[1][i][j] + dist[2][i][j];
                if (prison[i][j] == '#')
                    cnt -= 2;

                ret = min(ret, cnt);
            }
        }

        cout << ret << '\n';
    }
}