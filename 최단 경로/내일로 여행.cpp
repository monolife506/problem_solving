#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;

const ll INF = 1e12;
unordered_map<string, int> idx;
ll dist[2][100][100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill_n(&dist[0][0][0], 2 * 100 * 100, INF);

    int N, M, K, R;
    cin >> N >> R;
    for (int i = 0; i < N; ++i)
    {
        string city;
        cin >> city;
        idx[city] = i;
        dist[0][i][i] = dist[1][i][i] = 0;
    }

    cin >> M;
    vector<int> order(M);
    for (int i = 0; i < M; ++i)
    {
        string city;
        cin >> city;
        order[i] = idx[city];
    }

    cin >> K;
    for (int i = 0; i < K; ++i)
    {
        string type, from, to;
        cin >> type >> from >> to;

        ll cost;
        cin >> cost;
        cost *= 2;

        int u = idx[from], v = idx[to];

        dist[0][u][v] = min(dist[0][u][v], cost);
        dist[0][v][u] = min(dist[0][v][u], cost);
        if (type == "Mugunghwa" || type == "ITX-Saemaeul" || type == "ITX-Cheongchun")
        {
            dist[1][u][v] = 0;
            dist[1][v][u] = 0;
        }
        else if (type == "S-Train" || type == "V-Train")
        {
            dist[1][u][v] = min(dist[1][u][v], cost / 2);
            dist[1][v][u] = min(dist[1][v][u], cost / 2);
        }
        else
        {
            dist[1][u][v] = min(dist[1][u][v], cost);
            dist[1][v][u] = min(dist[1][v][u], cost);
        }
    }

    for (int k = 0; k < N; ++k)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                dist[0][i][j] = min(dist[0][i][j], dist[0][i][k] + dist[0][k][j]);
                dist[1][i][j] = min(dist[1][i][j], dist[1][i][k] + dist[1][k][j]);
            }
        }
    }

    ll sum[2] = {};
    for (int i = 0; i < M - 1; ++i)
    {
        sum[0] += dist[0][order[i]][order[i + 1]];
        sum[1] += dist[1][order[i]][order[i + 1]];
    }

    cout << (sum[0] > sum[1] + R * 2 ? "Yes" : "No") << '\n';
}