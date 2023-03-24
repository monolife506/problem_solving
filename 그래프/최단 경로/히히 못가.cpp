#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> P;

const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

int N, dist[1002][1002], root_size[1002][1002];
P root[1002][1002];
char buffer[1001], arr[1002][1002];

P find(P p)
{
    if (root[p.first][p.second].first == -1)
        return p;
    return root[p.first][p.second] = find(root[p.first][p.second]);
}

void merge(P a, P b)
{
    P root_a = find(a);
    P root_b = find(b);
    if (root_a != root_b)
    {
        root_size[root_a.first][root_a.second] += root_size[root_b.first][root_b.second];
        root[root_b.first][root_b.second] = root_a;
    }
}

int bfs()
{
    priority_queue<pair<int, P>, vector<pair<int, P>>, greater<pair<int, P>>> pq;
    fill_n(&dist[0][0], 1002 * 1002, 987654321);
    pq.push(make_pair(dist[N + 1][0] = 0, P(N + 1, 0)));

    while (!pq.empty())
    {
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        int d = pq.top().first;
        pq.pop();

        if (dist[y][x] < d)
            continue;

        for (size_t i = 0; i < 8; ++i)
        {
            int nxt_y = y + dy[i];
            int nxt_x = x + dx[i];
            if (nxt_x < 0 || nxt_x > N + 1 || nxt_y < 0 || nxt_y > N + 1)
                continue;
            if (arr[nxt_y][nxt_x] == '.')
                continue;

            P cur_root = find({y, x});
            if (cur_root != find({nxt_y, nxt_x}))
            {
                if (dist[nxt_y][nxt_x] > dist[y][x] + root_size[cur_root.first][cur_root.second])
                {
                    dist[nxt_y][nxt_x] = dist[y][x] + root_size[cur_root.first][cur_root.second];
                    pq.push(make_pair(dist[nxt_y][nxt_x], P(nxt_y, nxt_x)));
                }
            }
            else if (dist[nxt_y][nxt_x] > dist[y][x])
            {
                dist[nxt_y][nxt_x] = dist[y][x];
                pq.push(make_pair(dist[nxt_y][nxt_x], P(nxt_y, nxt_x)));
            }
        }
    }

    return dist[0][N + 1] - (2 * N - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill_n(&root[0][0], 1002 * 1002, P(-1, -1));
    fill_n(&root_size[0][0], 1002 * 1002, 1);

    cin >> N;
    for (size_t i = 1; i <= N; ++i)
    {
        cin >> buffer;
        for (size_t j = 1; j <= N; ++j)
            arr[i][j] = buffer[j - 1];
    }

    arr[0][0] = arr[0][1] = arr[1][0] = '.';
    arr[N][N + 1] = arr[N + 1][N] = arr[N + 1][N + 1] = '.';
    for (size_t i = 1; i <= N; ++i)
    {
        arr[i + 1][0] = arr[0][i + 1] = '0';
        arr[i - 1][N + 1] = arr[N + 1][i - 1] = '0';
    }

    for (int y = 0; y <= N + 1; ++y)
    {
        for (int x = 0; x <= N + 1; ++x)
        {
            for (size_t i = 0; i < 8; i += 2)
            {
                int nxt_y = y + dy[i];
                int nxt_x = x + dx[i];
                if (nxt_x < 0 || nxt_x > N + 1 || nxt_y < 0 || nxt_y > N + 1)
                    continue;
                if (arr[y][x] == arr[nxt_y][nxt_x])
                    merge({y, x}, {nxt_y, nxt_x});
            }
        }
    }

    cout << bfs() << '\n';
}