#include <iostream>
using namespace std;

const int INF = 987654321;
int num[1001], cache[3][31][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill_n(&cache[0][0][0], 3 * 31 * 1001, -INF);

    int T, W;
    cin >> T >> W;
    for (size_t i = 1; i <= T; ++i)
        cin >> num[i];

    cache[1][W][0] = 0;
    for (size_t t = 0; t < T; ++t)
    {
        for (size_t w = 0; w <= W; ++w)
        {
            cache[1][w][t + 1] =
                max(cache[1][w][t + 1], cache[1][w][t] + (num[t + 1] == 1));
            cache[2][w][t + 1] =
                max(cache[2][w][t + 1], cache[2][w][t] + (num[t + 1] == 2));

            if (w != 0)
            {
                cache[1][w - 1][t + 1] =
                    max(cache[1][w - 1][t + 1], cache[2][w][t] + (num[t + 1] == 1));
                cache[2][w - 1][t + 1] =
                    max(cache[2][w - 1][t + 1], cache[1][w][t] + (num[t + 1] == 2));
            }
        }
    }

    int ans = 0;
    for (size_t w = 0; w <= W; ++w)
    {
        ans = max(ans, cache[1][w][T]);
        ans = max(ans, cache[2][w][T]);
    }

    cout << ans << '\n';
}