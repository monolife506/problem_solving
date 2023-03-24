#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct FenwickTree
{
    size_t sz;
    vector<int> tree;

    FenwickTree(size_t sz) : sz(sz)
    {
        tree.resize(sz + 1, 0);
    }

    void update(int i, int val)
    {
        while (i <= sz)
        {
            tree[i] += val;
            i += (i & -i);
        }
    }

    int get_val(int i)
    {
        int ret = 0;
        while (i > 0)
        {
            ret += tree[i];
            i -= (i & -i);
        }

        return ret;
    }

    int get_val(int l, int r)
    {
        return get_val(r) - get_val(l - 1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    ll ans = 0;
    FenwickTree tree(n);
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;

        ans += tree.get_val(num + 1, n);
        tree.update(num, 1);
    }

    cout << ans << '\n';
}