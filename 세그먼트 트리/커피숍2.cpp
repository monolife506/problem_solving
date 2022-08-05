#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct FenwickTree
{
    size_t sz;
    vector<ll> tree;

    FenwickTree(size_t sz, vector<int> &v) : sz(sz)
    {
        tree.resize(sz + 1, 0);
        for (int i = 1; i < v.size(); ++i)
            update(i, v[i]);
    }

    void update(int i, ll val)
    {
        while (i <= sz)
        {
            tree[i] += val;
            i += (i & -i);
        }
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

    ll get_val(int l, int r)
    {
        return get_val(r) - get_val(l - 1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> v(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> v[i];

    FenwickTree tree(N, v);
    for (int i = 0; i < Q; ++i)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        if (x > y)
            swap(x, y);

        cout << tree.get_val(x, y) << '\n';
        tree.update(a, b - tree.get_val(a, a));
    }
}
