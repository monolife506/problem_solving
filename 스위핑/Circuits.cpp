#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

struct SegmentTree
{
    int *tree, *lazy;

    SegmentTree(size_t n)
    {
        tree = new int[n * 4];
        lazy = new int[n * 4];
        memset(tree, 0, sizeof(int) * n * 4);
        memset(lazy, 0, sizeof(int) * n * 4);
    }

    ~SegmentTree()
    {
        delete[] tree;
        delete[] lazy;
    }

    void propagate(int cur, int l, int r)
    {
        if (lazy[cur] == 0)
            return;

        if (l != r)
        {
            lazy[cur * 2] += lazy[cur];
            lazy[cur * 2 + 1] += lazy[cur];
        }

        tree[cur] += lazy[cur];
        lazy[cur] = 0;
    }

    int get_val(int cur, int l, int r, int L, int R)
    {
        propagate(cur, l, r);

        if (l > R || r < L)
            return INT32_MIN;
        if (l >= L && r <= R)
            return tree[cur];

        return max(get_val(cur * 2, l, (l + r) / 2, L, R),
                   get_val(cur * 2 + 1, (l + r) / 2 + 1, r, L, R));
    }

    void update(int cur, int l, int r, int L, int R, int val)
    {
        propagate(cur, l, r);

        if (l > R || r < L)
            return;
        if (l >= L && r <= R)
        {
            lazy[cur] += val;
            propagate(cur, l, r);
            return;
        }

        update(cur * 2, l, (l + r) / 2, L, R, val);
        update(cur * 2 + 1, (l + r) / 2 + 1, r, L, R, val);
        tree[cur] = max(tree[cur * 2], tree[cur * 2 + 1]);
    }
};

int get_idx(int val, vector<int> &v)
{
    return lower_bound(v.begin(), v.end(), val) - v.begin();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n;
    cin >> n;

    vector<int> y;
    vector<P> line;
    for (size_t i = 0; i < n; ++i)
    {
        int ux, uy, vx, vy;
        cin >> ux >> uy >> vx >> vy;
        y.push_back(uy);
        y.push_back(vy);
        line.push_back({uy, vy});
    }

    sort(y.begin(), y.end());
    y.erase(unique(y.begin(), y.end()), y.end());
    int y_size = y.size();

    SegmentTree tree(y_size);
    vector<vector<P>> bottom_y(y_size), top_y(y_size);
    for (size_t i = 0; i < n; ++i)
    {
        int L = get_idx(line[i].second, y);
        int R = get_idx(line[i].first, y);
        bottom_y[L].push_back({L, R});
        top_y[R].push_back({L, R});
        tree.update(1, 0, y_size - 1, L, R, 1);
    }

    int ans = 0, cnt = 0;
    for (size_t i = 0; i < y_size; ++i)
    {
        for (P &p : bottom_y[i])
        {
            tree.update(1, 0, y_size - 1, p.first, p.second, -1);
            ++cnt;
        }

        ans = max(ans, cnt + tree.get_val(1, 0, y_size - 1, 0, y_size - 1));
        for (P &p : top_y[i])
        {
            tree.update(1, 0, y_size - 1, p.first, p.second, 1);
            --cnt;
        }
    }

    cout << ans << '\n';
}

/*
1 2 3 3 2 2 2 2 2 1
*/