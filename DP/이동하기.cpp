#include <iostream>
using namespace std;

int num[1001][1001], cache[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
            cin >> num[i][j];
    }

    cache[1][1] = num[1][1];
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            if (i != 1)
                cache[i][j] = max(cache[i][j], cache[i - 1][j] + num[i][j]);
            if (j != 1)
                cache[i][j] = max(cache[i][j], cache[i][j - 1] + num[i][j]);
            if (i != 1 && j != 1)
                cache[i][j] = max(cache[i][j], cache[i - 1][j - 1] + num[i][j]);
        }
    }

    cout << cache[N][M] << '\n';
}