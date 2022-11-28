#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int w[] = {1, 2, 5, 10, 20, 50, 100};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int l = 0, r = 0;
    for (int i = 0; i < n; ++i)
    {
        int wi;
        cin >> wi;

        if (l <= r)
            l += wi;
        else
            r += wi;
    }

    int d = abs(r - l);
    int ans = 0;
    for (int i = 6; i >= 0; --i)
    {
        ans += (d / w[i]);
        d %= w[i];
    }

    cout << ans << '\n';
}