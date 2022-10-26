#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> tree[200001];
int s[200001];
map<pair<int, int>, ll> cache;

ll dp(int cur, int k)
{
    if (cache.find({cur, k}) != cache.end())
        return cache[{cur, k}];

    ll ret = 1LL * s[cur] * k;
    int child_cnt = tree[cur].size();

    if (child_cnt == 0)
        return ret;

    if (k % child_cnt == 0)
    {
        for (int nxt : tree[cur])
            ret += dp(nxt, k / child_cnt);
    }
    else
    {
        int nxt_k[2] = {k / child_cnt, k / child_cnt + 1};

        vector<ll> d;
        for (int nxt : tree[cur])
        {
            ret += dp(nxt, nxt_k[0]);
            d.push_back(dp(nxt, nxt_k[1]) - dp(nxt, nxt_k[0]));
        }

        sort(d.begin(), d.end(), greater<ll>());
        for (int i = 0; i < k % child_cnt; ++i)
            ret += d[i];
    }

    return cache[{cur, k}] = ret;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
        tree[i].clear();

    cache.clear();

    for (int i = 2; i <= n; ++i)
    {
        int p;
        cin >> p;
        tree[p].push_back(i);
    }

    for (int i = 1; i <= n; ++i)
        cin >> s[i];

    cout << dp(1, k) << '\n';
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

1
5 4
1 2 1 3
6 2 1 5 7

1
5 4
1 2 3 4
1 1 1 1 1

1
5 1
1 1 2 2
5 10 10 5 15

*/