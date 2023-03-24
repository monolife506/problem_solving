#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct FenwickTree
{
    const size_t sz;
    vector<ll> tree;

    FenwickTree(size_t sz) : sz(sz)
    {
        tree.resize(sz + 1, 0);
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

    ll get_val(int L, int R) { return get_val(R) - get_val(L - 1); }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    FenwickTree tree(N);
    for (int q = 0; q < Q; ++q)
    {
        int query;
        cin >> query;
        if (query == 1)
        {
            int p, x;
            cin >> p >> x;
            tree.update(p, x);
        }
        else
        {
            int p, q;
            cin >> p >> q;
            cout << tree.get_val(p, q) << '\n';
        }
    }
}