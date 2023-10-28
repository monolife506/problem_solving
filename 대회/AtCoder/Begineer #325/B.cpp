#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int w[1000], x[1000], l[1000], r[1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> w[i] >> x[i];

    int ans = 0;
    for (int i = 0; i < 24; ++i)
    {
        int tmp = 0;
        for (int j = 0; j < n; ++j)
        {
            int t = (i + x[j]) % 24;
            if (t >= 9 && t <= 17)
                tmp += w[j];
        }

        ans = max(ans, tmp);
    }

    cout << ans << '\n';
}