#include <iostream>
using namespace std;

int sz[1000], cache[1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> sz[i];

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        cache[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (sz[i] > sz[j])
                cache[i] = max(cache[i], cache[j] + 1);
        }

        ans = max(ans, cache[i]);
    }

    cout << ans << '\n';
}