#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
typedef long long ll;
typedef tuple<ll, ll, ll> t;

struct SegmentTree
{
    vector<ll> max_val, min_val, val;

    SegmentTree(size_t sz)
    {
        max_val.resize(sz * 4, 0);
        min_val.resize(sz * 4, 0);
        val.resize(sz * 4, 0);
    }

    void update(int cur, int l, int r, int i, int x)
    {
        if (i < l || i > r)
            return;

        if (l == r)
        {
            max_val[cur] = min_val[cur] = x;
            val[cur] = 0;
            return;
        }

        update(cur * 2, l, (l + r) / 2, i, x);
        update(cur * 2 + 1, (l + r) / 2 + 1, r, i, x);

        max_val[cur] = max(max_val[cur * 2], max_val[cur * 2 + 1]);
        min_val[cur] = min(min_val[cur * 2], min_val[cur * 2 + 1]);
        val[cur] = max(val[cur * 2], val[cur * 2 + 1]);
        val[cur] = max(val[cur], max_val[cur * 2 + 1] - min_val[cur * 2]);
    }

    t get_val(int cur, int l, int r, int L, int R)
    {
        if (l > R || r < L)
            return {-1e10, 1e10, -1e10};
        if (l >= L && r <= R)
            return {max_val[cur], min_val[cur], val[cur]};

        auto left = get_val(cur * 2, l, (l + r) / 2, L, R);
        auto right = get_val(cur * 2 + 1, (l + r) / 2 + 1, r, L, R);

        ll cur_max, cur_min, cur_val;
        cur_max = max(get<0>(left), get<0>(right));
        cur_min = min(get<1>(left), get<1>(right));
        cur_val = max(get<2>(left), get<2>(right));
        cur_val = max(cur_val, get<0>(right) - get<1>(left));

        return {cur_max, cur_min, cur_val};
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    SegmentTree tree(N);
    for (int i = 1; i <= N; ++i)
    {
        int a;
        cin >> a;
        tree.update(1, 1, N, i, a);
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            int k, x;
            cin >> k >> x;
            tree.update(1, 1, N, k, x);
        }
        else // q == 2
        {
            int l, r;
            cin >> l >> r;
            cout << get<2>(tree.get_val(1, 1, N, l, r)) << '\n';
        }
    }
}