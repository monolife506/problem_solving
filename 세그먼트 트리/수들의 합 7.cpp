#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct FenwickTree
{
    size_t sz;
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

    int N, M;
    cin >> N >> M;

    FenwickTree tree(N);
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0)
        {
            if (b > c)
                swap(b, c);

            cout << tree.get_val(b, c) << '\n';
        }
        else
            tree.update(b, c - tree.get_val(b, b));
    }
}