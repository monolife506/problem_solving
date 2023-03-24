#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    string flag;
    cin >> flag;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    vector<vector<int>> cache(2, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        if (flag[i - 1] == '0')
        {
            cache[0][i] = max(cache[0][i], max(cache[0][i - 1], cache[1][i - 1]));
        }
        else // flag[i - 1] == '1'
        {
            cache[0][i] = max(cache[0][i], cache[0][i - 1] + a[i - 1]);
            cache[1][i] = max(cache[1][i], max(cache[0][i - 1], cache[1][i - 1]) + a[i]);
        }
    }

    cout << max(cache[0][n], cache[1][n]) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solve();
}