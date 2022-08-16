#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct FenwickTree
{
    const size_t sz;
    vector<int> tree;

    FenwickTree(size_t sz) : sz(sz) { tree.resize(sz + 1, 0); }

    void add(int i, int val)
    {
        while (i <= sz)
        {
            tree[i] += val;
            i += (i & -i);
        }
    }

    int get_value(int i)
    {
        int ret = 0;
        while (i > 0)
        {
            ret += tree[i];
            i -= (i & -i);
        }

        return ret;
    }

    int get_value(int l, int r) { return get_value(r) - get_value(l - 1); }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 0; tc < T; ++tc)
    {
        int n;
        cin >> n;

        vector<int> seq(n), idx(n + 1);
        for (int i = 0; i < n; ++i)
        {
            cin >> seq[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            int num;
            cin >> num;
            idx[num] = i;
        }

        ll ans = 0;
        FenwickTree tree(n + 1);
        for (int i = 0; i < n; ++i)
        {
            ans += tree.get_value(idx[seq[i]], n + 1);
            tree.add(idx[seq[i]], 1);
        }

        cout << ans << '\n';
    }
}

/*

1 2 3 4 5
1 2 3 4 5

*/