#include <cstring>
#include <iostream>
using namespace std;

size_t N;
int card[1000], cache[2][1001][1001];

int dp(int turn, int i, int j)
{
    if (i + j == N)
        return 0;
    if (cache[turn][i][j] != -1)
        return cache[turn][i][j];

    if (turn)
        cache[turn][i][j] = max(dp(!turn, i + 1, j) + card[i], dp(!turn, i, j + 1) + card[N - (j + 1)]);
    else
        cache[turn][i][j] = min(dp(!turn, i + 1, j), dp(!turn, i, j + 1));

    return cache[turn][i][j];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t T;
    cin >> T;
    for (size_t tc = 0; tc < T; ++tc)
    {
        cin >> N;
        for (size_t i = 0; i < N; ++i)
            cin >> card[i];

        memset(cache, -1, sizeof(cache));
        cout << dp(true, 0, 0) << '\n';
    }
}