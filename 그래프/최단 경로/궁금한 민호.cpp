#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 987654321;

void floyd(vector<vector<int>> &dist)
{
    for (size_t k = 0; k < dist.size(); k++)
    {
        for (size_t i = 0; i < dist.size(); i++)
        {
            for (size_t j = 0; j < dist.size(); j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> dist(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cin >> dist[i][j];
    }

    vector<vector<int>> d = dist;
    floyd(d);
    if (d != dist)
    {
        cout << -1 << '\n';
    }
    else
    {
        int ans = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = i + 1; j < N; ++j)
                ans += dist[i][j];
        }

        for (int i = 0; i < N; ++i)
        {
            for (int j = i + 1; j < N; ++j)
            {
                if (i == j)
                    continue;

                vector<vector<int>> d = dist;
                d[i][j] = d[j][i] = INF;
                floyd(d);

                if (d == dist)
                    ans -= dist[i][j];
            }
        }

        cout << ans << '\n';
    }
}

/*

1-3 1
2-3 6

0 7 1
7 0 6
1 6 0

1-2 7
1-3 1
2-3 6

O-- 7 --O-- 6 --

*/