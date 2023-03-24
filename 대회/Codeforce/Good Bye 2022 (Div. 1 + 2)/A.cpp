#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> b(m);
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    for (int i = 0; i < m; ++i)
    {
        int idx = 0, diff = b[i] - a[0];
        for (int j = 1; j < n; ++j)
        {
            if (b[i] - a[j] > diff)
            {
                idx = j;
                diff = b[i] - a[j];
            }
        }

        a[idx] = b[i];
    }

    cout << accumulate(a.begin(), a.end(), 0LL) << '\n';
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