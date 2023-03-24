#include <algorithm>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;

struct RectLine
{
    int x, y1, y2, val;
    RectLine(int x = 0, int y1 = 0, int y2 = 0, int val = 1) : x(x), y1(y1), y2(y2), val(val) {}

    bool operator<(const RectLine &rhs) const { return (x != rhs.x) ? x < rhs.x : val < rhs.val; }
};

struct SegmentTree
{
    int *tree, *cnt;

    SegmentTree(size_t n)
    {
        tree = new int[n * 4];
        cnt = new int[n * 4];
        memset(tree, 0, sizeof(int) * n * 4);
        memset(cnt, 0, sizeof(int) * n * 4);
    }

    ~SegmentTree()
    {
        delete[] tree;
        delete[] cnt;
    }

    void update(int cur, int l, int r, int L, int R, int val, vector<int> &y)
    {
        if (l > R || r < L)
            return;

        if (l >= L && r <= R)
            cnt[cur] += val;
        else
        {
            update(cur * 2, l, (l + r) / 2, L, R, val, y);
            update(cur * 2 + 1, (l + r) / 2 + 1, r, L, R, val, y);
        }

        if (cnt[cur] != 0)
            tree[cur] = y[r + 1] - y[l];
        else
            tree[cur] = (l != r) ? tree[cur * 2] + tree[cur * 2 + 1] : 0;
    }
};

void coordinate_compression(vector<int> &v, unordered_map<int, int> &idx)
{
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    size_t n = v.size();
    for (size_t i = 0; i < n; ++i)
        idx[v[i]] = i;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N;
    cin >> N;

    vector<RectLine> line;
    vector<int> y;
    for (size_t i = 0; i < N; ++i)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        line.push_back(RectLine(x1, y1, y2, 1));
        line.push_back(RectLine(x2, y1, y2, -1));
        y.push_back(y1);
        y.push_back(y2);
    }

    sort(line.begin(), line.end());
    unordered_map<int, int> y_idx;
    coordinate_compression(y, y_idx);
    size_t y_idx_size = y_idx.size();

    ll ans = 0;
    SegmentTree tree(y_idx_size);

    tree.update(1, 0, y_idx_size - 2, y_idx[line[0].y1], y_idx[line[0].y2] - 1, line[0].val, y);
    for (size_t i = 1; i < N * 2; ++i)
    {
        int y1 = y_idx[line[i].y1];
        int y2 = y_idx[line[i].y2];
        ans += ll(tree.tree[1]) * (line[i].x - line[i - 1].x);
        tree.update(1, 0, y_idx_size - 2, y1, y2 - 1, line[i].val, y);
    }

    cout << ans << '\n';
}