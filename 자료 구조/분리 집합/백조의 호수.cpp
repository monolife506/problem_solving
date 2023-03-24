#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1500;
typedef pair<int, int> P;

int R, C;
char lake[MAX + 1][MAX + 1];
P root[MAX + 1][MAX + 1];

P find(P p)
{
    if (root[p.first][p.second].first == -1)
        return p;
    return root[p.first][p.second] = find(root[p.first][p.second]);
}

bool merge(P a, P b)
{
    P root_a = find(a);
    P root_b = find(b);
    char a_type = lake[root_a.first][root_a.second];
    char b_type = lake[root_b.first][root_b.second];
    if (root_a == root_b)
        return false;

    if (b_type == 'L')
        root[root_a.first][root_a.second] = root_b;
    else
        root[root_b.first][root_b.second] = root_a;

    return (a_type == 'L' && b_type == 'L');
}

int bfs()
{
    const int dy[] = {1, -1, 0, 0};
    const int dx[] = {0, 0, 1, -1};

    queue<pair<P, int>> q;

    // 초기화
    for (size_t i = 0; i < R; i++)
        for (size_t j = 0; j < C; j++)
            root[i][j] = {-1, -1};

    // 전처리
    for (size_t i = 0; i < R; i++)
    {
        for (size_t j = 0; j < C; j++)
        {
            if (lake[i][j] == 'X')
                continue;

            for (size_t k = 0; k < 4; k++)
            {
                P nxt = {i + dy[k], j + dx[k]};
                if (nxt.first < 0 || nxt.first >= R || nxt.second < 0 || nxt.second >= C)
                    continue;
                if (lake[nxt.first][nxt.second] == 'X')
                    q.push(make_pair(nxt, 1));
                else
                    merge(P(i, j), nxt);
            }
        }
    }

    while (!q.empty())
    {
        P cur = q.front().first;
        int day = q.front().second;
        q.pop();

        if (lake[cur.first][cur.second] != 'X')
            continue;

        lake[cur.first][cur.second] = '.';
        for (size_t i = 0; i < 4; i++)
        {
            P nxt = {cur.first + dy[i], cur.second + dx[i]};
            if (nxt.first < 0 || nxt.first >= R || nxt.second < 0 || nxt.second >= C)
                continue;

            if (lake[nxt.first][nxt.second] == 'X')
                q.push(make_pair(nxt, day + 1));
            else if (merge(cur, nxt))
                return day;
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C;
    for (size_t i = 0; i < R; i++)
        cin >> lake[i];

    cout << bfs() << '\n';
}