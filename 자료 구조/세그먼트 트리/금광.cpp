#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

struct Node
{
    ll sum = 0, l_val = 0, r_val = 0, val = 0;
};

struct SegmentTree
{
    vector<Node> tree;

    SegmentTree(size_t sz) { tree.resize(4 * sz); }

    void add(int cur, int l, int r, int idx, ll val)
    {
        if (l > idx || r < idx)
            return;

        if (l == r)
        {
            tree[cur].sum += val;
            tree[cur].l_val = tree[cur].sum;
            tree[cur].r_val = tree[cur].sum;
            tree[cur].val = tree[cur].sum;
            return;
        }

        add(cur * 2, l, (l + r) / 2, idx, val);
        add(cur * 2 + 1, (l + r) / 2 + 1, r, idx, val);

        Node &left = tree[cur * 2];
        Node &right = tree[cur * 2 + 1];
        tree[cur].sum = left.sum + right.sum;
        tree[cur].l_val = max(left.l_val, left.sum + right.l_val);
        tree[cur].r_val = max(left.r_val + right.sum, right.r_val);
        tree[cur].val = max(max(left.val, right.val), left.r_val + right.l_val);
    }

    Node get_node(int cur, int l, int r, int L, int R)
    {
        if (l > R || r < L)
            return Node();
        if (l >= L && r <= R)
            return tree[cur];

        Node left = get_node(cur * 2, l, (l + r) / 2, L, R);
        Node right = get_node(cur * 2 + 1, (l + r) / 2 + 1, r, L, R);
        Node ret;

        ret.sum = left.sum + right.sum;
        ret.l_val = max(left.l_val, left.sum + right.l_val);
        ret.r_val = max(left.r_val + right.sum, right.r_val);
        ret.val = max(max(left.val, right.val), left.r_val + right.l_val);

        return ret;
    }
};

inline int get_idx(int val, const vector<int> &v)
{
    return lower_bound(v.begin(), v.end(), val) - v.begin();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<P, int>> gold_mines(N);
    vector<int> x, y;
    for (auto &gm : gold_mines)
    {
        cin >> gm.first.first >> gm.first.second >> gm.second;
        x.push_back(gm.first.first);
        y.push_back(gm.first.second);
    }

    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    sort(y.begin(), y.end());
    y.erase(unique(y.begin(), y.end()), y.end());

    vector<vector<P>> p(x.size());
    for (auto &gm : gold_mines)
    {
        int x_idx = get_idx(gm.first.first, x);
        int y_idx = get_idx(gm.first.second, y);
        p[x_idx].push_back({y_idx, gm.second});
    }

    ll ans = 0;
    SegmentTree tree(y.size());
    for (int L = 0; L < x.size(); ++L)
    {
        for (int R = L; R < x.size(); ++R)
        {
            for (int i = 0; i < p[R].size(); ++i)
                tree.add(1, 0, y.size() - 1, p[R][i].first, p[R][i].second);

            ans = max(ans, tree.tree[1].val);
        }
        for (int R = L; R < x.size(); ++R)
        {
            for (int i = 0; i < p[R].size(); ++i)
                tree.add(1, 0, y.size() - 1, p[R][i].first, -p[R][i].second);
        }
    }

    cout << ans << '\n';
}