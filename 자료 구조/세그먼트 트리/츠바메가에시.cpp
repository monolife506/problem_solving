#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int MAX = 1e6;

struct SegmentTree
{
    vector<pair<ll, ll>> tree;

    SegmentTree(const vector<ll> &v)
    {
        tree.resize(4 * (MAX + 1));
        init(1, 0, MAX, v);
    }

    void init(int cur, int l, int r, const vector<ll> &v)
    {
        if (l == r)
        {
            tree[cur].first = v[l];
            tree[cur].second = 0;
            return;
        }

        init(cur * 2, l, (l + r) / 2, v);
        init(cur * 2 + 1, (l + r) / 2 + 1, r, v);

        vector<ll> tmp = {tree[cur * 2].first, tree[cur * 2].second, tree[cur * 2 + 1].first, tree[cur * 2 + 1].second};
        sort(tmp.begin(), tmp.end());

        tree[cur].first = tmp[3];
        tree[cur].second = tmp[2];
    }

    void add(int cur, int l, int r, int idx, ll val)
    {
        if (l > idx || r < idx)
            return;

        if (l == r)
        {
            tree[cur].first += val;
            return;
        }

        add(cur * 2, l, (l + r) / 2, idx, val);
        add(cur * 2 + 1, (l + r) / 2 + 1, r, idx, val);

        vector<ll> tmp = {tree[cur * 2].first, tree[cur * 2].second, tree[cur * 2 + 1].first, tree[cur * 2 + 1].second};
        sort(tmp.begin(), tmp.end());

        tree[cur].first = tmp[3];
        tree[cur].second = tmp[2];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<pair<int, int>>> x_p(MAX + 1), y_p(MAX + 1);
    vector<ll> x_sum(MAX + 1, 0), y_sum(MAX + 1, 0);
    for (int i = 0; i < N; ++i)
    {
        int x, y, v;
        cin >> x >> y >> v;
        x_p[x].push_back({y, v});
        y_p[y].push_back({x, v});
        x_sum[x] += v;
        y_sum[y] += v;
    }

    ll ans = 0;
    SegmentTree x_tree(x_sum);
    SegmentTree y_tree(y_sum);

    for (int i = 0; i <= MAX; ++i)
    {
        for (pair<int, int> &p : x_p[i])
            y_tree.add(1, 0, MAX, p.first, -p.second);

        ans = max(ans, x_sum[i] + y_tree.tree[1].first + y_tree.tree[1].second);

        for (pair<int, int> &p : x_p[i])
            y_tree.add(1, 0, MAX, p.first, p.second);
    }
    for (int i = 0; i <= MAX; ++i)
    {
        for (pair<int, int> &p : y_p[i])
            x_tree.add(1, 0, MAX, p.first, -p.second);

        ans = max(ans, y_sum[i] + x_tree.tree[1].first + x_tree.tree[1].second);

        for (pair<int, int> &p : y_p[i])
            x_tree.add(1, 0, MAX, p.first, p.second);
    }

    sort(x_sum.begin(), x_sum.end());
    sort(y_sum.begin(), y_sum.end());
    ans = max(ans, x_sum[MAX] + x_sum[MAX - 1] + x_sum[MAX - 2]);
    ans = max(ans, y_sum[MAX] + y_sum[MAX - 1] + y_sum[MAX - 2]);

    cout << ans << '\n';
}