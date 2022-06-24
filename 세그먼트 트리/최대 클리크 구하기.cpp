#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

struct FenwickTree
{
    const size_t sz;
    vector<int> tree;

    FenwickTree(const size_t sz) : sz(sz) { tree.resize(sz + 1, 0); };

    void add(int i, int val)
    {
        while (i <= sz)
        {
            tree[i] += val;
            i += (i & -i);
        }
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

inline int get_idx(int num, const vector<int> &v)
{
    return lower_bound(v.begin(), v.end(), num) - v.begin();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<P> interval(N);
    vector<int> x;
    for (P &p : interval)
    {
        cin >> p.first >> p.second;
        x.push_back(p.first);
        x.push_back(p.second);
    }

    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());

    FenwickTree tree(x.size());
    for (P &p : interval)
    {
        int s = get_idx(p.first, x) + 1;
        int e = get_idx(p.second, x) + 1;

        tree.add(s, 1);
        if (e + 1 <= x.size())
            tree.add(e + 1, -1);
    }

    int ans = 0;
    int ans_idx = 0;
    for (int i = 1; i <= x.size(); ++i)
    {
        if (ans < tree.sum(i))
        {
            ans = tree.sum(i);
            ans_idx = i;
        }
    }

    cout << ans << '\n';
    for (int i = 0; i < N; ++i)
    {
        int s = get_idx(interval[i].first, x) + 1;
        int e = get_idx(interval[i].second, x) + 1;
        if (s <= ans_idx && ans_idx <= e)
            cout << i + 1 << " ";
    }
    cout << '\n';
}