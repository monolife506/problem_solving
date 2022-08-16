#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

struct SegmentTree
{
    vector<P> tree;

    SegmentTree(size_t sz) { tree.resize(sz * 4, {0, 0}); }

    void update(int cur, int l, int r, int i, ll val)
    {
        if (i < l || i > r)
            return;

        if (l == r)
        {
            if (l % 2 == 0)
                tree[cur].first += val;
            else
                tree[cur].second += val;

            return;
        }

        update(cur * 2, l, (l + r) / 2, i, val);
        update(cur * 2 + 1, (l + r) / 2 + 1, r, i, val);
        tree[cur].first = tree[cur * 2].first + tree[cur * 2 + 1].first;
        tree[cur].second = tree[cur * 2].second + tree[cur * 2 + 1].second;
    }

    P get_value(int cur, int l, int r, int L, int R)
    {
        if (l > R || r < L)
            return {0, 0};
        if (l >= L && r <= R)
            return tree[cur];

        P left = get_value(cur * 2, l, (l + r) / 2, L, R);
        P right = get_value(cur * 2 + 1, (l + r) / 2 + 1, r, L, R);
        return make_pair(left.first + right.first, left.second + right.second);
    };
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    SegmentTree tree(N);
    for (int i = 1; i <= N; ++i)
    {
        int c;
        cin >> c;
        tree.update(1, 1, N, i, c);
    }

    for (int q = 0; q < Q; ++q)
    {
        int query;
        cin >> query;
        if (query == 1)
        {
            int L, R;
            cin >> L >> R;

            P p = tree.get_value(1, 1, N, L, R);
            cout << abs(p.first - p.second) << '\n';
        }
        else
        {
            int L, x;
            cin >> L >> x;
            tree.update(1, 1, N, L, x);
        }
    }
}