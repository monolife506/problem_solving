#include <iostream>
using namespace std;
typedef long long ll;

ll N, K;

inline ll parent(ll n) { return (n + K - 2) / K; }

ll depth(ll n)
{
    ll ret = 0;
    while (parent(n) != 0)
    {
        n = parent(n);
        ret++;
    }

    return ret;
}

ll query(ll x, ll y)
{
    if (K == 1)
        return abs(x - y);

    ll x_depth = depth(x);
    ll y_depth = depth(y);
    ll lca_depth = y_depth;

    if (x_depth > y_depth)
    {
        swap(x, y);
        swap(x_depth, y_depth);
        lca_depth = y_depth;
    }

    while (x_depth != lca_depth)
    {
        y = parent(y);
        lca_depth--;
    }

    if (x == y)
        return (x_depth + y_depth) - 2 * lca_depth;

    while (x != y)
    {
        x = parent(x);
        y = parent(y);
        lca_depth--;
    }

    return (x_depth + y_depth) - 2 * lca_depth;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int Q;
    cin >> N >> K >> Q;
    for (size_t i = 0; i < Q; i++)
    {
        ll x, y;
        cin >> x >> y;
        cout << query(x, y) << '\n';
    }
}

/*
1
2 ~ 4 (1 * 3 + 1)
5 ~ 13 (4 * 3 + 1)
14 ~ 40 (13 * 3 + 1)
*/