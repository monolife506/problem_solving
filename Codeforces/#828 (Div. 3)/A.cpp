#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    string s;
    cin >> s;

    bool flag = true;
    vector<char> c(51, -1);
    for (int i = 0; i < n; ++i)
    {
        if (c[a[i]] == -1)
        {
            c[a[i]] = s[i];
        }
        else if (c[a[i]] != s[i])
        {
            flag = false;
        }
    }

    cout << (flag ? "YES" : "NO") << '\n';
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