#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct FenwickTree
{
    const size_t sz;
    vector<ll> tree;
    FenwickTree(const size_t sz) : sz(sz) { tree.resize(sz + 1, 0); }

    void add(int i, ll x)
    {
        while (i <= sz)
        {
            tree[i] += x;
            i += (i & -i);
        }
    }

    void add(int l, int r, ll x)
    {
        add(l, x);
        if (r < sz)
            add(r + 1, -x);
    }

    ll get_val(int i)
    {
        ll ret = 0;
        while (i > 0)
        {
            ret += tree[i];
            i -= (i & -i);
        }

        return ret;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    FenwickTree tree(n);
    for (int i = 0; i < q; ++i)
    {
        int query;
        cin >> query;
        if (query == 1)
        {
            int l, r;
            cin >> l >> r;
            tree.add(l, r, 1);
        }
        else // query == 2
        {
            int x;
            cin >> x;

            int cnt = tree.get_val(x);
            int num = a[x];
            while (num >= 10 && cnt > 0)
            {
                string str = to_string(num);

                num = 0;
                for (char c : str)
                    num += c - '0';

                cnt--;
            }

            cout << num << '\n';
        }
    }
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