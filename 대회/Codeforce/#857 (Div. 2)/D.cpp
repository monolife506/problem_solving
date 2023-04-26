#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    vector<pii> p(n);
    multiset<int> a, a_minus;
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i].second >> p[i].first;
        a.insert(p[i].second);
        a_minus.insert(-p[i].second);
    }

    sort(p.begin(), p.end(), greater<pii>());

    int ans = INT32_MAX, al = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i != 0)
        {
            al = max(al, p[i - 1].second);
            ans = min(ans, abs(p[i].first - al));
        }

        a.erase(a.find(p[i].second));
        a_minus.erase(a_minus.find(-p[i].second));

        auto lo = a_minus.lower_bound(-p[i].first);
        if (lo != a_minus.end() && -(*lo) >= al)
            ans = min(ans, abs(p[i].first + *lo));

        auto hi = a.lower_bound(p[i].first);
        if (hi != a.end() && *hi >= al)
            ans = min(ans, abs(p[i].first - *hi));
    }

    cout << ans << '\n';
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

10 -> 1 2 3 2
7 -> 4
5 -> 4 ~
5 -> 4 ~
3 -> 4 ~

*/