#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    multiset<int> a;
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        a.insert(num);
    }

    int ans = 0;
    while (!a.empty())
    {
        auto cur = a.begin();
        while (true)
        {
            auto nxt = a.find(*cur + 1);

            a.erase(cur);
            if (nxt == a.end())
                break;
            else
                cur = nxt;
        }

        ans++;
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