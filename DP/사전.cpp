#include <iostream>
using namespace std;

const int INF = 1e9 + 7;

int cache[201][201];

void kth(int n, int m, int k)
{
    if (n == 0)
    {
        for (size_t i = 0; i < m; ++i)
            cout << 'z';
        return;
    }
    if (m == 0)
    {
        for (size_t i = 0; i < n; ++i)
            cout << 'a';
        return;
    }

    if (k <= cache[n - 1 + m][n - 1])
    {
        cout << 'a';
        kth(n - 1, m, k);
    }
    else
    {
        cout << 'z';
        kth(n, m - 1, k - cache[n + m - 1][n - 1]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    for (size_t i = 1; i <= N + M; ++i)
    {
        cache[i][0] = cache[i][i] = 1;
        for (size_t j = 1; j < i; ++j)
        {
            cache[i][j] = cache[i - 1][j - 1] + cache[i - 1][j];
            if (cache[i][j] > INF)
                cache[i][j] = INF + 1;
        }
    }

    if (cache[N + M][N] < K)
    {
        cout << -1 << '\n';
    }
    else
    {
        kth(N, M, K);
        cout << '\n';
    }
}

/*

aazz
azaz
azza
zaaz
zaza
zzaa

*/
