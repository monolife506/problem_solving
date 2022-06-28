#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int N, K;
ll H[100001], A[100001], B[100001];

struct FenwickTree
{
    const size_t sz;
    vector<ll> tree;

    FenwickTree(size_t sz) : sz(sz) { tree.resize(sz + 1, 0); }

    void add(int i, ll val)
    {
        while (i <= sz)
        {
            tree[i] += val;
            i += (i & -i);
        }
    }

    void add(int l, int r, ll val)
    {
        add(l, val);
        if (r < sz)
            add(r + 1, -val);
    }

    ll get_sum(int i)
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

ll ternary_search(ll l, ll r, FenwickTree &linear_term, FenwickTree &constant_term)
{
    while (r - l >= 3)
    {
        ll p = (l * 2 + r) / 3;
        ll q = (l + r * 2) / 3;
        ll p_val = linear_term.get_sum(p) * p + constant_term.get_sum(p);
        ll q_val = linear_term.get_sum(q) * q + constant_term.get_sum(q);

        if (p_val > q_val)
            l = p;
        else
            r = q;
    }

    ll ret = INT64_MAX;
    for (ll i = l; i <= r; ++i)
        ret = min(ret, linear_term.get_sum(i) * i + constant_term.get_sum(i));

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
        cin >> H[i];
    for (int i = 1; i <= N; ++i)
        cin >> A[i];
    for (int i = 1; i <= N; ++i)
        cin >> B[i];

    ll ans = INT64_MAX;
    FenwickTree linear_term(100001), constant_term(100001);
    for (int i = 1; i <= N; ++i)
    {
        linear_term.add(1, H[i] - 1, -B[i]);
        constant_term.add(1, H[i] - 1, B[i] * H[i]);
        linear_term.add(H[i], 100001, A[i]);
        constant_term.add(H[i], 100001, -A[i] * H[i]);
        if (i >= K)
        {
            ans = min(ans, ternary_search(1, 100000, linear_term, constant_term));
            linear_term.add(1, H[i - K + 1] - 1, B[i - K + 1]);
            constant_term.add(1, H[i - K + 1] - 1, -B[i - K + 1] * H[i - K + 1]);
            linear_term.add(H[i - K + 1], 100001, -A[i - K + 1]);
            constant_term.add(H[i - K + 1], 100001, A[i - K + 1] * H[i - K + 1]);
        }
    }

    cout << ans << '\n';
}

/*

if (h >= H[i]): abs(h - H[i]) * A[i] -> A[i] * h - A[i] * H[i]
else: abs(h - H[i]) * B[i] -> - B[i] * h + B[i] * H[i]

4 2
1 2 2 1
1 1 1 1
1 1 1 1
0

*/