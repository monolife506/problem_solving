// 1389번: 케빈 베이컨의 6단계 법칙

#include <iostream>
#include <array>
using namespace std;
const int INF = 10000;

array<array<int, 101>, 101> dist;

void floyd(int N)
{
    for (size_t k = 1; k <= N; k++)
    {
        for (size_t i = 1; i <= N; i++)
        {
            for (size_t j = 1; j <= N; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }  
}

int main()
{
    int N, M;
    cin >> N >> M;
    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 1; j <= N; j++)
        {
            dist[i][j] = dist[j][i] = ((i == j) ? 0 : INF);
        }
    }

    for (size_t i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        dist[a][b] = dist[b][a] = 1;
    }

    floyd(N);
    int ans = 0;
    int max_dist = INF;
    for (size_t i = 1; i <= N; i++)
    {
        int total = 0;
        for (size_t j = 1; j <= N; j++)
           total += dist[i][j];

        if (total < max_dist)
        {
            max_dist = total;
            ans = i;
        }
    }
    cout << ans;
}