#include <iostream>
#include <vector>
using namespace std;
const int INF = 987654321;

int dist[101][101], pre[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill_n(&dist[0][0], 101 * 101, INF);

    size_t n, m;
    cin >> n >> m;
    for (size_t i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (dist[a][b] > c)
        {
            dist[a][b] = c;
            pre[a][b] = a;
        }
    }

    for (size_t i = 1; i <= n; ++i)
        dist[i][i] = 0;

    for (size_t k = 1; k <= n; ++k)
    {
        for (size_t i = 1; i <= n; ++i)
        {
            for (size_t j = 1; j <= n; ++j)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pre[i][j] = pre[k][j];
                }
            }
        }
    }

    for (size_t i = 1; i <= n; ++i)
    {
        for (size_t j = 1; j <= n; ++j)
            cout << (dist[i][j] != INF ? dist[i][j] : 0) << " ";

        cout << '\n';
    }

    for (size_t i = 1; i <= n; ++i)
    {
        for (size_t j = 1; j <= n; ++j)
        {
            if (dist[i][j] == INF || dist[i][j] == 0)
            {
                cout << 0 << '\n';
                continue;
            }

            vector<int> path;
            for (int k = j; k != 0; k = pre[i][k])
                path.push_back(k);

            cout << path.size() << " ";
            for (int k = path.size() - 1; k >= 0; --k)
                cout << path[k] << " ";

            cout << '\n';
        }
    }
}