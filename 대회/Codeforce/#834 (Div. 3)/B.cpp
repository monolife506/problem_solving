#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int m, s;
    cin >> m >> s;

    int max_b = 0;
    vector<bool> flag(51, false);
    for (int i = 0; i < m; ++i)
    {
        int b;
        cin >> b;
        flag[b] = true;
        max_b = max(max_b, b);
    }

    int sum = 0;
    for (int i = 1; i <= max_b; ++i)
    {
        if (!flag[i])
            sum += i;
    }

    if (sum < s)
    {
        int i = max_b + 1;
        while (sum < s)
            sum += i++;

        if (sum == s)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    else if (sum == s)
    {
        cout << "YES" << '\n';
    }
    else
    {
        cout << "NO" << '\n';
    }
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