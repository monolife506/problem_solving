#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct Node
{
    ll sum = 0;
    ll l_val = -20000000000;
    ll r_val = -20000000000;
    ll val = -20000000000;
};

class SegmentTree
{
private:
    const size_t sz;
    vector<Node> tree;

    void init(int cur, int l, int r, const vector<int> &v)
    {
        if (l == r)
        {
            tree[cur].sum = v[l];
            tree[cur].l_val = v[l];
            tree[cur].r_val = v[l];
            tree[cur].val = v[l];
            return;
        }

        init(cur * 2, l, (l + r) / 2, v);
        init(cur * 2 + 1, (l + r) / 2 + 1, r, v);

        const Node &left = tree[cur * 2];
        const Node &right = tree[cur * 2 + 1];

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

public:
    SegmentTree(const size_t sz, const vector<int> &v) : sz(sz)
    {
        tree.resize(sz * 4);
        init(1, 1, sz, v);
    }

    Node get_node(int L, int R) { return get_node(1, 1, sz, L, R); }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> A[i];

    int M;
    cin >> M;

    SegmentTree tree(N, A);
    for (int q = 0; q < M; ++q)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (y1 < x2)
        {
            ll left = tree.get_node(x1, y1).r_val;
            ll mid = (x2 - y1 > 1) ? tree.get_node(y1 + 1, x2 - 1).sum : 0;
            ll right = tree.get_node(x2, y2).l_val;

            cout << left + mid + right << '\n';
        }
        else
        {
            Node mid = tree.get_node(x2, y1);

            ll ans = mid.val;
            ans = max(ans, (x1 < x2) ? tree.get_node(x1, x2 - 1).r_val + mid.l_val : mid.l_val);
            ans = max(ans, (y1 < y2) ? mid.r_val + tree.get_node(y1 + 1, y2).l_val : mid.r_val);

            ll left = max((x1 < x2) ? tree.get_node(x1, x2 - 1).r_val : 0LL, 0LL);
            ll right = max((y1 < y2) ? tree.get_node(y1 + 1, y2).l_val : 0LL, 0LL);
            ans = max(ans, left + mid.sum + right);

            cout << ans << '\n';
        }
    }
}