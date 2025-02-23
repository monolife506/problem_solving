#include <bits/stdc++.h>
#define endl '\n'
// #define FILE_RW
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

struct SegTree
{
    vector<ll> tree;

    SegTree(int n)
    {
        tree.resize(n * 4, 0);
    }

    void update(int cur, int l, int r, int idx, int val)
    {
        if (idx < l || idx > r)
            return;

        if (l == r)
        {
            tree[cur] += val;
            return;
        }

        update(cur * 2, l, (l + r) / 2, idx, val);
        update(cur * 2 + 1, (l + r) / 2 + 1, r, idx, val);

        tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
    }

    ll query(int cur, int l, int r, int L, int R)
    {
        if (l > R || r < L)
            return 0;
        if (L <= l && r <= R)
            return tree[cur];

        return query(cur * 2, l, (l + r) / 2, L, R) +
               query(cur * 2 + 1, (l + r) / 2 + 1, r, L, R);
    }
};

int psearch(int k, SegTree &st)
{
    int l = 1;
    int r = 1'000'000;
    int mid, ans;

    while (l <= r)
    {
        mid = (l + r) / 2;
        if (st.query(1, 1, 1'000'000, 1, mid) >= k)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return ans;
}

void solve()
{
    int n;
    cin >> n;

    SegTree st(1'000'000);
    for (int qi = 0; qi < n; ++qi)
    {
        int a, b;
        cin >> a >> b;

        if (a == 1)
        {
            int val = psearch(b, st);
            st.update(1, 1, 1'000'000, val, -1);

            cout << val << endl;
        }
        else // a == 2
        {
            int c;
            cin >> c;
            st.update(1, 1, 1'000'000, b, c);
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

    solve();
}

/*

일차함수로 증가/감소하는 값에 대해서
어떤 상한/하한이 존재

*/