#include <iostream>
using namespace std;

const int MAX = 1000;
const int MOD = 1'000'000'007;
typedef long long ll;

int N, M;
ll cache[MAX + 1][MAX + 1];

int calculate()
{
    cache[1][1] = 1;

    for (size_t j = 1; j <= M; j++)
    {
        for (size_t i = 1; i <= N; i++)
        {
            if (i == 1 && j == 1)
                continue;
            if (cache[i][j] == -1)
                continue;

            if (i > 1 && cache[i - 1][j] != -1)
                cache[i][j] += cache[i - 1][j];
            if (j > 1 && cache[i][j - 1] != -1)
                cache[i][j] += cache[i][j - 1];
            if (i < N && j % 2 == 0 && cache[i + 1][j - 1] != -1)
                cache[i][j] += cache[i + 1][j - 1];
            if (i > 1 && j % 2 == 1 && j > 1 && cache[i - 1][j - 1] != -1)
                cache[i][j] += cache[i - 1][j - 1];

            cache[i][j] %= MOD;
        }
    }

    return cache[N][M];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int K;
    cin >> N >> M >> K;
    for (size_t i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        cache[x][y] = -1;
    }

    cout << calculate() << '\n';
}