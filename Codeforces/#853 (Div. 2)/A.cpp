#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i + 1 < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (gcd(a[i], a[j]) <= 2)
            {
                cout << "Yes" << '\n';
                return;
            }
        }
    }

    cout << "No" << '\n';
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