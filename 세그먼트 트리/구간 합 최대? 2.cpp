#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct Node
{
    ll sum, l_val, r_val, val;
    Node(ll sum, ll l_val, ll r_val, ll val)
        : sum(sum), l_val(l_val), r_val(r_val), val(val) {}
};

// 최대 구간합 세그먼트 트리
struct SegmentTree
{
    const size_t N;
    vector<Node> tree;

    SegmentTree(size_t N, const vector<int> &v) : N(N)
    {
        tree.resize(N * 4, Node(0, 0, 0, 0));
        init(1, 1, N, v);
    }

    void init(int cur, int l, int r, const vector<int> &v)
    {
        if (l == r)
        {
            tree[cur] = Node(v[l], v[l], v[l], v[l]);
            return;
        }

        init(cur * 2, l, (l + r) / 2, v);
        init(cur * 2 + 1, (l + r) / 2 + 1, r, v);

        Node &left = tree[cur * 2];
        Node &right = tree[cur * 2 + 1];
        tree[cur].sum = left.sum + right.sum;
        tree[cur].l_val = max(left.l_val, left.sum + right.l_val);
        tree[cur].r_val = max(left.r_val + right.sum, right.r_val);
        tree[cur].val = max(max(left.val, right.val), left.r_val + right.l_val);
    }

    void update(int cur, int l, int r, int idx, ll val)
    {
        if (l > idx || r < idx)
            return;

        if (l == r)
        {
            tree[cur] = Node(val, val, val, val);
            return;
        }

        update(cur * 2, l, (l + r) / 2, idx, val);
        update(cur * 2 + 1, (l + r) / 2 + 1, r, idx, val);

        Node &left = tree[cur * 2];
        Node &right = tree[cur * 2 + 1];
        tree[cur].sum = left.sum + right.sum;
        tree[cur].l_val = max(left.l_val, left.sum + right.l_val);
        tree[cur].r_val = max(left.r_val + right.sum, right.r_val);
        tree[cur].val = max(max(left.val, right.val), left.r_val + right.l_val);
    }

    Node get_value(int cur, int l, int r, int L, int R)
    {
        if (l > R || r < L)
            return Node(-1e10, -1e10, -1e10, -1e10);
        if (l >= L && r <= R)
            return tree[cur];

        Node left = get_value(cur * 2, l, (l + r) / 2, L, R);
        Node right = get_value(cur * 2 + 1, (l + r) / 2 + 1, r, L, R);
        Node ret = Node(0, 0, 0, 0);
        ret.sum = left.sum + right.sum;
        ret.l_val = max(left.l_val, left.sum + right.l_val);
        ret.r_val = max(left.r_val + right.sum, right.r_val);
        ret.val = max(max(left.val, right.val), left.r_val + right.l_val);

        return ret;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q, U, V;
    cin >> N >> Q >> U >> V;

    vector<int> K(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        cin >> K[i];
        K[i] = U * K[i] + V;
    }

    SegmentTree tree(N, K);
    for (int q = 0; q < Q; ++q)
    {
        int C, A, B;
        cin >> C >> A >> B;
        if (C == 0)
            cout << tree.get_value(1, 1, N, A, B).val - V << '\n';
        else // C == 1
            tree.update(1, 1, N, A, U * B + V);
    }
}