#include <iostream>
using namespace std;

const int INF = 987654321;
int N, sz[1001], cache[201][1001][1001];

int dp(int d, int i, int j)
{
    if (i == 0)
        return d;
    if (cache[d + 100][i][j] != INF)
        return cache[d + 100][i][j];

    int &ret = cache[d + 100][i][j];
    if (d <= 0)
    {
        ret = max(dp(d + sz[j], i - 1, (j + 1) % N),
                  dp(d + sz[(i + j - 1) % N], i - 1, j));
    }
    else // d > 0
    {
        ret = min(dp(d - sz[j], i - 1, (j + 1) % N),
                  dp(d - sz[(i + j - 1) % N], i - 1, j));
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill_n(&cache[0][0][0], 201 * 1001 * 1001, INF);

    int max_diff = -INF;
    int total_sz = 0;

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> sz[i];
        total_sz += sz[i];
    }

    for (int i = 0; i < N; ++i)
    {
        max_diff = max(max_diff, dp(0, N, i));
        // max_diff = max(max_diff, dp(sz[i], N - 1, (i + 1) % N)); TLE -> why..?
    }

    cout << (total_sz + max_diff) / 2 << '\n';
}