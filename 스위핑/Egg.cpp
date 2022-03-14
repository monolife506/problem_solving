#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_Y = 100000;

struct Line
{
    int x, y1, y2, val;
    explicit Line(int x, int y1, int y2, int val)
        : x(x), y1(y1), y2(y2), val(val) {}

    bool operator<(const Line &rhs)
    {
        return (x != rhs.x) ? x < rhs.x : val < rhs.val;
    }
};

struct SegmentTree
{
    int *tree;

    SegmentTree(size_t n)
    {
        tree = new int[n * 4];
        memset(tree, 0, sizeof(int) * n * 4);
    }

    ~SegmentTree() { delete[] tree; }

    void update(int cur, int lo, int hi, int L, int R, int k)
    {
        if (lo > R || hi < L)
            return;

        if (L <= lo && R >= hi)
        {
            tree[cur] += k;
            return;
        }
        else
        {
            int mid = (lo + hi) / 2;
            update(cur * 2, lo, mid, L, R, k);
            update(cur * 2 + 1, mid + 1, hi, L, R, k);
        }
    }

    int get_val(int cur, int lo, int hi, int idx)
    {
        if (lo == hi)
            return tree[cur];

        int ret = tree[cur];
        int mid = (lo + hi) / 2;
        if (lo <= idx && idx <= mid)
            ret += get_val(cur * 2, lo, mid, idx);
        else if (idx > mid && idx <= hi)
            ret += get_val(cur * 2 + 1, mid + 1, hi, idx);

        return ret;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t T;
    cin >> T;
    for (size_t tc = 0; tc < T; ++tc)
    {
        size_t n, m;
        cin >> n >> m;

        vector<Line> line;
        for (size_t i = 0; i < n; ++i)
        {
            int x, y;
            cin >> x >> y;
            line.push_back(Line(x, y, y, 0));
        }
        for (size_t i = 0; i < m; ++i)
        {
            int l, r, b, t;
            cin >> l >> r >> b >> t;
            line.push_back(Line(l, b, t, -1));
            line.push_back(Line(r, b, t, 1));
        }

        SegmentTree y_cnt(MAX_Y + 1);
        sort(line.begin(), line.end());

        int ans = 0;
        for (size_t i = 0; i < n + m * 2; ++i)
        {
            if (line[i].val == 0)
                ans += y_cnt.get_val(1, 0, MAX_Y, line[i].y1);
            else
                y_cnt.update(1, 0, MAX_Y, line[i].y1, line[i].y2, -line[i].val);
        }

        cout << ans << '\n';
    }
}