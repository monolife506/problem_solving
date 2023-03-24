// 11404번: 플로이드
// 한번의 시행으로 모든 정점 쌍 사이의 거리를 구할 수 있음

#include <iostream>
#include <vector>
using namespace std;

const int INF = INT32_MAX;
typedef long long ll;

void floyd(vector<vector<ll>>& dist)
{
    int N = dist.size() - 1;
    for (size_t k = 1; k <= N; k++)
    {
        for (size_t i = 1; i <= N; i++)
        {
            for (size_t j = 1; j <= N; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<ll>> dist(N + 1, vector<ll>(N + 1, INF));
    for (size_t i = 1; i <= N; i++)
        dist[i][i] = 0;

    for (size_t i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], (ll)c);
    }

    floyd(dist);
    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 1; j <= N; j++)
        {
            cout << ((dist[i][j] == INF) ? 0 : dist[i][j]) << " ";
        }
        cout << '\n';
    }
}