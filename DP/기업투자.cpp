#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int profit[21][301], cache[21][301], cost[21][21][301];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        int tmp;
        cin >> tmp;
        for (int j = 1; j <= M; ++j)
            cin >> profit[j][i];
    }

    for (int i = 1; i <= M; ++i)
    {
        for (int j = 0; j <= N; ++j)
        {
            cache[i][j] = cache[i - 1][j];
            for (int l = 1; l <= M; ++l)
                cost[l][i][j] = cost[l][i - 1][j];

            for (int k = 1; k <= j; ++k)
            {
                if (cache[i][j] < cache[i - 1][j - k] + profit[i][k])
                {
                    cache[i][j] = cache[i - 1][j - k] + profit[i][k];
                    for (int l = 1; l <= M; ++l)
                    {
                        if (i == l)
                            cost[l][i][j] = cost[l][i - 1][j - k] + k;
                        else
                            cost[l][i][j] = cost[l][i - 1][j - k];
                    }
                }
            }
        }
    }

    int ans = -1;
    int ans_cost;
    for (int i = 0; i <= N; ++i)
    {
        if (ans < cache[M][i])
        {
            ans = cache[M][i];
            ans_cost = i;
        }
    }

    cout << ans << '\n';
    for (int i = 1; i <= M; ++i)
        cout << cost[i][M][ans_cost] << " ";

    cout << '\n';
}