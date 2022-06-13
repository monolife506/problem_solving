#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;

struct Node
{
    int sum, l_val, r_val, val;
    Node(int sum = 0, int l_val = -INF, int r_val = -INF, int val = -INF)
        : sum(sum), l_val(l_val), r_val(r_val), val(val) {}
};

struct SegmentTree
{
    vector<Node> tree;

    SegmentTree(vector<int> &v)
    {
        tree.resize(4 * v.size());
        init(1, 1, v.size(), v);
    }

    void init(int cur, int l, int r, vector<int> &v)
    {
        if (l == r)
        {
            tree[cur].sum = v[l - 1];
            tree[cur].l_val = v[l - 1];
            tree[cur].r_val = v[l - 1];
            tree[cur].val = v[l - 1];
            return;
        }

        init(cur * 2, l, (l + r) / 2, v);
        init(cur * 2 + 1, (l + r) / 2 + 1, r, v);

        tree[cur].sum = tree[cur * 2].sum + tree[cur * 2 + 1].sum;
        tree[cur].l_val = max(tree[cur * 2].l_val, tree[cur * 2].sum + tree[cur * 2 + 1].l_val);
        tree[cur].r_val = max(tree[cur * 2 + 1].r_val, tree[cur * 2].r_val + tree[cur * 2 + 1].sum);
        tree[cur].val = max(max(tree[cur * 2].val, tree[cur * 2 + 1].val), tree[cur * 2].r_val + tree[cur * 2 + 1].l_val);
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
        ret.r_val = max(right.r_val, left.r_val + right.sum);
        ret.val = max(max(left.val, right.val), left.r_val + right.l_val);

        return ret;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < A.size(); i++)
        cin >> A[i];

    SegmentTree segment_tree(A);

    cin >> M;
    for (int query = 0; query < M; ++query)
    {
        int i, j;
        cin >> i >> j;
        cout << segment_tree.get_node(1, 1, N, i, j).val << '\n';
    }
}