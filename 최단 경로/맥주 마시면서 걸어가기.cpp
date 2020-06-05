// 9205번: 맥주 마시면서 걸어가기

#include <iostream>
#include <array>
#include <vector>
using namespace std;

const int INF = 1000000;
typedef pair<int, int> P;

int getDist(P &A, P &B)
{
    return abs(A.first - B.first) + abs(A.second - B.second);
}

void floyd(vector<vector<int>> &dist, int N)
{
    for (size_t k = 0; k < N; k++)
    {
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < N; j++)
            {
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    size_t T;
    cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        int N;
        cin >> N;

        // 0 == 집, N + 1 == 락 페스티벌
        vector<P> point(N + 2);
        vector<vector<int>> dist(N + 2, vector<int>(N + 2, INF));

        for (auto &p : point)
            cin >> p.first >> p.second;

        for (size_t j = 0; j < N + 2; j++)
        {
            for (size_t k = 0; k < N + 2; k++)
            {
                int d = getDist(point[j], point[k]);
                if (d <= 1000)
                    dist[j][k] = d;
            }
        }

        floyd(dist, N + 2);
        cout << ((dist[0][N + 1] != INF) ? "happy\n" : "sad\n");
    }
}