#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct FenwickTree
{
    size_t n;
    ll *tree;

    FenwickTree(size_t n) : n(n) { tree = new ll[n + 1]; }
    ~FenwickTree() { delete[] tree; }

    ll sum(int i)
    {
        ll ret = 0;
        while (i > 0)
        {
            ret += tree[i];
            i -= (i & -i);
        }

        return ret;
    }

    void add(int i, ll num)
    {
        while (i <= n)
        {
            tree[i] += num;
            i += (i & -i);
        }
    }
};

ll inversion_counting(vector<int> &v)
{
    size_t n = v.size();
    FenwickTree tree(n);

    vector<int> sorted = v;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    ll ret = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        int idx = lower_bound(sorted.begin(), sorted.end(), v[i]) - sorted.begin() + 1;
        ret += tree.sum(idx - 1);
        tree.add(idx, 1);
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N;
    cin >> N;

    vector<int> v(N);
    for (size_t i = 0; i < N; ++i)
        cin >> v[i];

    cout << inversion_counting(v) << '\n';
}

/*
3 2 1 -> 2 3 1 -> 2 1 3 -> 1 2 3
inversion counting
*/