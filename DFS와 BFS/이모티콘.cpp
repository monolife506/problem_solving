#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;

const int INF = 987654321;

int bfs(int start, int dest)
{
    static int time[2001][2001];
    fill_n(&time[0][0], 2001 * 2001, INF);

    queue<P> q;
    q.push({1, 0});
    time[1][0] = 0;

    while (!q.empty())
    {
        int cur = q.front().first;
        int copied = q.front().second;
        q.pop();

        if (time[cur][cur] > time[cur][copied] + 1)
        {
            time[cur][cur] = time[cur][copied] + 1;
            q.push({cur, cur});
        }
        if (cur + copied <= 2000 && time[cur + copied][copied] > time[cur][copied] + 1)
        {
            time[cur + copied][copied] = time[cur][copied] + 1;
            q.push({cur + copied, copied});
        }
        if (cur >= 1 && time[cur - 1][copied] > time[cur][copied] + 1)
        {
            time[cur - 1][copied] = time[cur][copied] + 1;
            q.push({cur - 1, copied});
        }
    }

    int ans = INF;
    for (size_t i = 0; i <= 2000; ++i)
        ans = min(ans, time[dest][i]);

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int S;
    cin >> S;

    cout << bfs(1, S) << '\n';
}