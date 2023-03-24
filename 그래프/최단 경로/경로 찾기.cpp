// 11403번: 경로 찾기

#include <iostream>
using namespace std;
const int INF = 100000;

int N;
int dist[101][101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 1; j <= N; j++)
        {
            cin >> dist[i][j];
            if (dist[i][j] == 0)
                dist[i][j] = INF;
        }
    }

    for (size_t k = 1; k <= N; k++)
        for (size_t i = 1; i <= N; i++)
            for (size_t j = 1; j <= N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 1; j <= N; j++)
        {
            cout << (dist[i][j] != INF) << " ";
        }
        cout << '\n';
    }
}