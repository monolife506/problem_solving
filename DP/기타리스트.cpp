#include <iostream>
using namespace std;

int V[50];
bool cache[50][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, S, M;
    cin >> N >> S >> M;
    for (int i = 0; i < N; ++i)
        cin >> V[i];

    if (S + V[0] <= M)
        cache[0][S + V[0]] = true;
    if (S - V[0] >= 0)
        cache[0][S - V[0]] = true;

    for (int i = 1; i <= N - 1; ++i)
    {
        for (int j = 0; j <= M; ++j)
        {
            if (!cache[i - 1][j])
                continue;

            if (j + V[i] <= M)
                cache[i][j + V[i]] = true;
            if (j - V[i] >= 0)
                cache[i][j - V[i]] = true;
        }
    }

    int ans = -1;
    for (int i = 0; i <= M; ++i)
    {
        if (cache[N - 1][i])
            ans = max(ans, i);
    }

    cout << ans << '\n';
}