#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int R, C;
char parking_lot[51][51];
vector<P> cars, parking_places;

vector<P> bigraph[100];
int matched[100];
bool visited[100];

void bfs(int c_num, P start)
{
    static const int INF = 987654321;
    static const int dy[] = {-1, 0, 1, 0};
    static const int dx[] = {0, 1, 0, -1};

    queue<P> q;
    q.push(start);

    vector<vector<int>> dist(R, vector<int>(C, INF));
    dist[start.first][start.second] = 0;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nxt_y = y + dy[i];
            int nxt_x = x + dx[i];
            if (nxt_y < 0 || nxt_y >= R || nxt_x < 0 || nxt_x >= C)
                continue;
            if (parking_lot[nxt_y][nxt_x] == 'X')
                continue;

            if (dist[nxt_y][nxt_x] == INF)
            {
                dist[nxt_y][nxt_x] = dist[y][x] + 1;
                q.push({nxt_y, nxt_x});
            }
        }
    }

    for (int p_num = 0; p_num < parking_places.size(); ++p_num)
    {
        int &y = parking_places[p_num].first;
        int &x = parking_places[p_num].second;
        if (dist[y][x] != INF)
            bigraph[c_num].push_back({p_num, dist[y][x]});
    }
}

bool match(int cur, int max_time)
{
    if (visited[cur])
        return false;

    visited[cur] = true;
    for (P &p : bigraph[cur])
    {
        int &nxt = p.first;
        int &t = p.second;
        if ((t <= max_time) && (matched[nxt] == -1 || match(matched[nxt], max_time)))
        {
            matched[nxt] = cur;
            return true;
        }
    }

    return false;
}

int bipartite_matching(int max_time)
{
    int match_cnt = 0;
    memset(matched, -1, sizeof(matched));
    for (int i = 0; i < cars.size(); ++i)
    {
        memset(visited, false, sizeof(visited));
        match_cnt += match(i, max_time);
    }

    return match_cnt;
}

int parametric_seatch(int l, int r)
{
    int ret;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (bipartite_matching(mid) == cars.size())
        {
            ret = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C;
    for (int i = 0; i < R; ++i)
    {
        cin >> parking_lot[i];
        for (int j = 0; j < C; ++j)
        {
            if (parking_lot[i][j] == 'C')
                cars.push_back({i, j});
            else if (parking_lot[i][j] == 'P')
                parking_places.push_back({i, j});
        }
    }

    // 이분 그래프 만들기
    for (int c_num = 0; c_num < cars.size(); ++c_num)
        bfs(c_num, cars[c_num]);

    if (bipartite_matching(R * C) != cars.size())
        cout << -1 << '\n';
    else
        cout << parametric_seatch(0, R * C) << '\n';
}