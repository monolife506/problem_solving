#include <iostream>
using namespace std;

const int INF = 100000;
int a[251], b[251], cache[251][62501];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill_n(&cache[0][0], 251 * 62501, INF);

    int n;
    cin >> n;
    for (size_t i = 1; i <= n; ++i)
        cin >> a[i] >> b[i];

    cache[0][0] = 0;
    for (size_t i = 1; i <= n; ++i)
    {
        for (size_t j = 0; j <= (n - 1) * 250; ++j)
        {
            cache[i][j + a[i]] = min(cache[i][j + a[i]], cache[i - 1][j]);
            cache[i][j] = min(cache[i][j], cache[i - 1][j] + b[i]);
        }
    }

    int ans = INF;
    for (int t = 0; t <= n * 250; ++t)
        ans = min(ans, max(cache[n][t], t));

    cout << ans << '\n';
}