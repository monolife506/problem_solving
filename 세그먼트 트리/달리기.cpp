#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

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

int get_idx(int num, vector<int> &v)
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

    vector<int> skill(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> skill[i];

    vector<int> skill_sorted = skill;
    sort(skill_sorted.begin(), skill_sorted.end());
    skill_sorted.erase(unique(skill_sorted.begin(), skill_sorted.end()), skill_sorted.end());

    FenwickTree tree(N);
    for (int i = 1; i <= N; ++i)
    {
        int idx = get_idx(skill[i], skill_sorted);
        cout << i - tree.get_val(idx) << '\n';
        tree.update(idx, 1);
    }
}