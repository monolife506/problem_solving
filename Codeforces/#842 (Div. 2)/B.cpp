#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n, k;
    cin >> n >> k;

    int cnt = 0, cur = 1;

    vector<int> p(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];

        if (p[i] == cur)
            cur++;
        else if (p[i] > cur)
            cnt++;
    }

    cout << (cnt % k == 0 ? cnt / k : cnt / k + 1) << '\n';
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