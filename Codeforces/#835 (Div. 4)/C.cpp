#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<int> s(n), sorted;
    for (int i = 0; i < n; ++i)
        cin >> s[i];

    sorted = s;
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == sorted[n - 1])
            cout << sorted[n - 1] - sorted[n - 2] << " ";
        else
            cout << s[i] - sorted[n - 1] << " ";
    }

    cout << '\n';
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