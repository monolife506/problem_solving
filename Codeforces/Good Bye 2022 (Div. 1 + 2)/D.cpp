#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 998244353;

int find(int n, vector<int> &root)
{
    return (root[n] < 0) ? n : root[n] = find(root[n], root);
}

void merge(int a, int b, vector<int> &root, vector<int> &edge_cnt, vector<bool> &contains_self_loop)
{
    a = find(a, root);
    b = find(b, root);
    if (a != b)
    {
        root[a] += root[b];
        root[b] = a;
        edge_cnt[a] += edge_cnt[b];

        if (contains_self_loop[b])
            contains_self_loop[a] = true;
    }
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> b(n);
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    vector<int> root(n + 1, -1), edge_cnt(n + 1, 0);
    vector<bool> contains_self_loop(n + 1, false);
    for (int i = 0; i < n; ++i)
    {
        merge(a[i], b[i], root, edge_cnt, contains_self_loop);
        edge_cnt[find(a[i], root)]++;
        if (a[i] == b[i])
            contains_self_loop[find(a[i], root)] = true;
    }

    ll ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (i == find(i, root))
        {
            if (edge_cnt[i] != abs(root[i]))
            {
                cout << 0 << '\n';
                return;
            }
            else
            {
                ans *= (contains_self_loop[i]) ? n : 2;
                ans %= MOD;
            }
        }
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

3 3 1 3 4
4 5 2 5 5
c가 존재 -> 1 ~ n이 각각 다른 i에 존재

1

*/