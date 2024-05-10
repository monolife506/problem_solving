#include <bits/stdc++.h>
// #define FILE_RW
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct FenwickTree
{
    size_t sz;
    vector<int> tree;

    FenwickTree(size_t n) : sz(n)
    {
        tree.resize(sz + 1, 0);
    }

    void add(int i, int val)
    {
        while (i <= sz)
        {
            tree[i] += val;
            i += (i & -i);
        }
    }

    void add(int l, int r, int val)
    {
        add(l, val);
        if (r < sz)
            add(r + 1, -val);
    }

    int sum(int i)
    {
        int ret = 0;
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
    int n;
    cin >> n;

    string s;
    cin >> s;

    for (int k = n; k > 0; --k)
    {
        FenwickTree tree(n);
        for (int i = 1; i <= n; ++i)
        {
            if (s[i - 1] == '1')
                tree.add(i, i, 1);
        }
        for (int i = 1; i + k - 1 <= n; ++i)
        {

            int val = tree.sum(i);

            if (val % 2 == 0)
                tree.add(i, i + k - 1, 1);
        }

        bool flag = true;
        for (int i = 1; i <= n; ++i)
        {
            int val = tree.sum(i);
            if (val % 2 == 0)
            {
                flag = false;
            }
        }

        if (flag)
        {
            cout << k << '\n';
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef FILE_RW
    freopen("local.in", "r", stdin);
    freopen("local.out", "w", stdout);
#endif

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}

/*

00100

*/