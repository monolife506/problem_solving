#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;

struct FenwickTree
{
    size_t sz;
    vector<ll> tree;

    FenwickTree(size_t sz) : sz(sz) { tree.resize(sz + 1, 0); }

    void update(int i, ll val)
    {
        while (i <= sz)
        {
            tree[i] += val;
            i += (i & -i);
        }
    }

    void update(int l, int r, ll val)
    {
        update(l, val);
        if (r + 1 <= sz)
            update(r + 1, -val);
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
};

struct Ingredient
{
    int l, r, v;
    Ingredient(int l, int r, int v) : l(l), r(r), v(v) {}
    bool operator<(const Ingredient &rhs) const
    {
        if (l != rhs.l)
            return l < rhs.l;
        else
            return r > rhs.r;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<Ingredient> ing;
    for (int i = 0; i < N; ++i)
    {
        int l, r, v;
        cin >> l >> r >> v;
        ing.push_back({l, r, v});
    }

    sort(ing.begin(), ing.end());

    vector<int> candidates, candidates_v;
    int idx = 0;
    FenwickTree tree(N);
    candidates.push_back(ing[idx].r);
    candidates_v.push_back(ing[idx].v);
    for (int i = 1; i < N; ++i)
    {
        if (ing[idx].r < ing[i].r)
        {
            idx = i;
            candidates.push_back(ing[idx].r);
            candidates_v.push_back(ing[idx].v);
        }
        else
        {
            int lo = lower_bound(candidates.begin(), candidates.end(), ing[i].r) - candidates.begin();
            tree.update(lo + 1, candidates.size(), ing[i].v);
        }
    }

    ll ans = 0;
    for (int i = 0; i < candidates.size(); ++i)
        ans = max(ans, tree.get_val(i + 1) + candidates_v[i]);

    cout << ans << '\n';
}

/*

3
1 4 11
2 7 10
2 3 2
22

6
1 4 1
2 3 1
3 5 1
4 4 1
5 5 1
6 8 1

1 4
3 5
6 8

*/