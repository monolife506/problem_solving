// 14938번: 서강그라운드

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000;

int N, M, R;
int item[101];
int dist[101][101];

void floyd()
{
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
    cout.tie(0);
    fill(&dist[0][0], &dist[100][101], INF);

    cin >> N >> M >> R;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> item[i];
        dist[i][i] = 0;
    }
    for (size_t i = 0; i < R; i++)
    {
        int A, B, L;
        cin >> A >> B >> L;
        dist[A][B] = min(dist[A][B], L);
        dist[B][A] = min(dist[B][A], L);
    }
    floyd();

    int ans = 0;
    for (size_t i = 1; i <= N; i++)
    {
        int totalItem = 0;
        for (size_t j = 1; j <= N; j++)
        {
            if (M >= dist[i][j])
                totalItem += item[j];
        }
        ans = max(ans, totalItem);
    }
    cout << ans;
}