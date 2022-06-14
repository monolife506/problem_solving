#include <iostream>
#include <vector>
using namespace std;

const int MAX_S = 500'000;

struct SegmentTree
{
    vector<int> tree;

    SegmentTree(size_t sz) { tree.resize(4 * sz, 0); }

    void update(int cur, int l, int r, int idx, int val)
    {
        if (l > idx || r < idx)
            return;

        if (l == r)
        {
            tree[cur] = val;
            return;
        }

        update(cur * 2, l, (l + r) / 2, idx, val);
        update(cur * 2 + 1, (l + r) / 2 + 1, r, idx, val);
        tree[cur] = max(tree[cur * 2], tree[cur * 2 + 1]);
    }

    int get_value(int cur, int l, int r, int L, int R)
    {
        if (l > R || r < L)
            return 0;
        if (l >= L && r <= R)
            return tree[cur];

        return max(get_value(cur * 2, l, (l + r) / 2, L, R),
                   get_value(cur * 2 + 1, (l + r) / 2 + 1, r, L, R));
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, k, d;
    cin >> N >> k >> d;

    vector<int> S(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> S[i];

    int ans = 0;
    vector<int> cache_k(k, 0);
    SegmentTree cache_d(500'000);
    for (int i = 1; i <= N; ++i)
    {
        int L = max(1, S[i] - d);
        int R = min(S[i] + d, MAX_S);
        int max_len = max(cache_k[S[i] % k], cache_d.get_value(1, 1, MAX_S, L, R)) + 1;

        cache_k[S[i] % k] = max_len;
        cache_d.update(1, 1, MAX_S, S[i], max_len);
        ans = max(ans, max_len);
    }

    cout << ans << '\n';
}