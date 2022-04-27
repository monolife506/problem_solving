#include <iostream>
using namespace std;

int num[100000], cache[2][100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; ++i)
        cin >> num[i];

    int ans = num[0];

    cache[0][0] = num[0];
    for (size_t i = 1; i < n; ++i)
    {
        cache[0][i] = max(num[i], cache[0][i - 1] + num[i]);
        ans = max(ans, cache[0][i]);
    }

    cache[1][0] = 0;
    for (size_t i = 1; i < n; ++i)
    {
        if (cache[0][i - 1] < 0)
            cache[1][i] = cache[1][i - 1] + num[i];
        else
            cache[1][i] = max(cache[0][i] - num[i], cache[1][i - 1] + num[i]);

        ans = max(ans, cache[1][i]);
    }

    cout << ans << '\n';
}