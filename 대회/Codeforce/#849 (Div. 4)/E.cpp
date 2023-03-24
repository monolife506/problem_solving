#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] < 0)
        {
            cnt++;
            a[i] = -a[i];
        }
    }

    if (cnt % 2 == 0)
        cout << accumulate(a.begin(), a.end(), 0LL) << '\n';
    else
        cout << accumulate(a.begin(), a.end(), 0LL) - (*min_element(a.begin(), a.end()) * 2) << '\n';
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

/*

*/