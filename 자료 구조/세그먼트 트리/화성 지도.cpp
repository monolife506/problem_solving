#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

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

    void update(int cur, int l, int r, int L, int R, int val)
    {
        if (l > R || r < L)
            return;

        if (l >= L && r <= R)
            cnt[cur] += val;
        else
        {
            update(cur * 2, l, (l + r) / 2, L, R, val);
            update(cur * 2 + 1, (l + r) / 2 + 1, r, L, R, val);
        }

        if (cnt[cur] != 0)
            tree[cur] = r - l + 1;
        else
            tree[cur] = (l != r) ? tree[cur * 2] + tree[cur * 2 + 1] : 0;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N;
    cin >> N;

    vector<RectLine> line;
    for (size_t i = 0; i < N; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        line.push_back(RectLine(x1, y1, y2, 1));
        line.push_back(RectLine(x2, y1, y2, -1));
    }

    int ans = 0;
    SegmentTree tree(30000);

    sort(line.begin(), line.end());
    tree.update(1, 0, 29999, line[0].y1, line[0].y2 - 1, line[0].val);
    for (size_t i = 1; i < N * 2; ++i)
    {
        ans += tree.tree[1] * (line[i].x - line[i - 1].x);
        tree.update(1, 0, 29999, line[i].y1, line[i].y2 - 1, line[i].val);
    }

    cout << ans << '\n';
}