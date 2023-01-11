#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int max_l = INT32_MIN;
    int min_r = INT32_MAX;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'L')
            max_l = max(max_l, i);
        else
            min_r = min(min_r, i);
    }

    if (max_l > min_r)
        cout << 0 << '\n';
    else if (max_l + 1 == min_r)
        cout << max_l + 1 << '\n';
    else
        cout << -1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}