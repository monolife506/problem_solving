// 1956번: 운동

#include <iostream>
using namespace std;

constexpr int INF = 1000000000;
typedef pair<int, int> P;

int dist[401][401];

int main()
{
    int V, E;
    cin >> V >> E;

    for (size_t i = 1; i <= V; i++)
        for (size_t j = 1; j <= V; j++)
            dist[i][j] = INF;

    for (size_t i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
    }

    for (size_t i = 1; i <= V; i++)
        for (size_t j = 1; j <= V; j++)
            for (size_t k = 1; k <= V; k++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int ans = INF;
    for (size_t i = 1; i <= V; i++)
        ans = min(ans, dist[i][i]);

    cout << ((ans != INF) ? ans : -1) << '\n';
}