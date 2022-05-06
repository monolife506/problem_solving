#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

const int MAX_N = 100000;
const int MAX_VAL = 1000000;

struct FenwickTree
{
    ll *tree;
    size_t sz;

    FenwickTree(size_t n)
    {
        tree = new ll[sz = n + 1];
        memset(tree, 0, sizeof(ll) * sz);
    }

    ~FenwickTree() { delete[] tree; }

    void add(int i, ll val)
    {
        while (i < sz)
        {
            tree[i] += val;
            i += (i & -i);
        }
    }

    ll sum(int i)
    {
        ll ret = 0;
        while (i > 0)
        {
            ret += tree[i];
            i -= (i & -i);
        }

        return ret;
    }

    ll sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
};

struct P
{
    int p, q, idx;
    P(int p = 0, int q = 0, int idx = 0) : p(p), q(q), idx(idx) {}
};

P seq[MAX_N];
ll cnt[2][MAX_N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; ++i)
        cin >> seq[i].p;
    for (size_t i = 0; i < n; ++i)
        cin >> seq[i].q;
    for (size_t i = 0; i < n; ++i)
        seq[i].idx = i;

    sort(seq, seq + n, [](P &lhs, P &rhs) -> bool
         { return (lhs.p != rhs.p) ? lhs.p < rhs.p : lhs.q < rhs.q; });

    FenwickTree tree(MAX_VAL + 1);
    stack<int> s;

    for (int i = 0; i < n; ++i)
    {
        cnt[0][seq[i].idx] = tree.sum(1, seq[i].q);
        s.push(seq[i].q + 1);
        if (i == n - 1 || seq[i].p != seq[i + 1].p)
        {
            while (!s.empty())
            {
                tree.add(s.top(), 1);
                s.pop();
            }
        }
    }

    memset(tree.tree, 0, sizeof(ll) * (MAX_VAL + 2));
    for (int i = n - 1; i >= 0; --i)
    {
        cnt[1][seq[i].idx] = tree.sum(seq[i].q + 2, MAX_VAL + 1);
        s.push(seq[i].q + 1);
        if (i == 0 || seq[i].p != seq[i - 1].p)
        {
            while (!s.empty())
            {
                tree.add(s.top(), 1);
                s.pop();
            }
        }
    }

    ll ans = 0;
    for (size_t i = 0; i < n; ++i)
        ans += cnt[0][i] * cnt[1][i];

    cout << ans << '\n';
}
