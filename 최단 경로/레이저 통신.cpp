#include <deque>
#include <iostream>
using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int MAX = 100;
const int INF = 987654321;
typedef pair<int, int> P;

int w, h;
char arr[MAX + 1][MAX + 1];
int cost[4][MAX + 1][MAX + 1];

int bfs(P start, P dest)
{
    deque<pair<int, P>> d;

    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < h; j++)
            for (size_t k = 0; k < w; k++)
                cost[i][j][k] = INF;

    for (size_t i = 0; i < 4; i++)
    {
        P nxt = {start.first + dy[i], start.second + dx[i]};
        if (nxt.first < 0 || nxt.first >= h || nxt.second < 0 || nxt.second >= w)
            continue;

        if (arr[nxt.first][nxt.second] != '*')
        {
            cost[i][nxt.first][nxt.second] = 0;
            d.push_back(make_pair(i, nxt));
        }
    }

    while (!d.empty())
    {
        int y = d.front().second.first;
        int x = d.front().second.second;
        int dir = d.front().first;
        d.pop_front();

        for (size_t i = 0; i < 4; i++)
        {
            P nxt = {y + dy[i], x + dx[i]};
            if (nxt.first < 0 || nxt.first >= h || nxt.second < 0 || nxt.second >= w)
                continue;
            if (arr[nxt.first][nxt.second] == '*' || start == nxt)
                continue;

            int weight = (dir != i);
            if (cost[i][nxt.first][nxt.second] > cost[dir][y][x] + weight)
            {
                cost[i][nxt.first][nxt.second] = cost[dir][y][x] + weight;
                (weight == 0) ? d.push_front(make_pair(i, nxt)) : d.push_back(make_pair(i, nxt));
            }
        }
    }

    int ret = INF;
    for (size_t i = 0; i < 4; i++)
        ret = min(ret, cost[i][dest.first][dest.second]);

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    P start = {-1, -1}, dest = {-1, -1};
    cin >> w >> h;
    for (size_t i = 0; i < h; i++)
    {
        cin >> arr[i];
        for (size_t j = 0; j < w; j++)
            if (arr[i][j] == 'C')
                (start.first == -1) ? start = {i, j} : dest = {i, j};
    }

    cout << bfs(start, dest) << '\n';
}
