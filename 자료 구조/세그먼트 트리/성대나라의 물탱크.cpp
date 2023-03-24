#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct SegmentTree
{
    size_t capacity;
    ll *tree;

    SegmentTree(size_t n)
    {
        capacity = 1;
        while (capacity < n)
            capacity *= 2;

        tree = new ll[capacity * 2];
        memset(tree, 0, sizeof(ll) * capacity * 2);
    }

    ~SegmentTree() { delete[] tree; }

    ll get_sum(int L, int R)
    {
        ll ret = 0;
        for (L += capacity, R += capacity; L < R; L /= 2, R /= 2)
        {
            if (L % 2 == 1)
                ret += tree[L++];
            if (R % 2 == 0)
                ret += tree[R--];
        }

        return (L == R) ? ret + tree[L] : ret;
    }

    void update(int idx, int val)
    {
        tree[capacity + idx] += val;
        for (int i = (capacity + idx) / 2; i > 0; i /= 2)
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
};

int depth[200001], in[200001], out[200001];
vector<int> tree[200001];

void dfs(int cur, int parent, int cur_depth)
{
    static int nth = 0;

    depth[cur] = cur_depth;
    in[cur] = ++nth;
    for (int nxt : tree[cur])
    {
        if (in[nxt] == 0)
            dfs(nxt, cur, cur_depth + 1);
    }

    out[cur] = nth;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N, C, Q;
    cin >> N >> C;
    for (size_t i = 0; i < N - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    cin >> Q;

    dfs(C, -1, 1);
    SegmentTree cnt(N);
    for (size_t i = 0; i < Q; ++i)
    {
        int q, a;
        cin >> q >> a;
        if (q == 1)
            cnt.update(in[a], 1);
        else // q == 2
            cout << cnt.get_sum(in[a], out[a]) * depth[a] << '\n';
    }
}