#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

struct SegmentTree
{
    int *tree;

    SegmentTree(size_t n)
    {
        tree = new int[n * 4];
        memset(tree, 0, sizeof(int) * n * 4);
    }

    ~SegmentTree() { delete[] tree; }

    void update(int cur, int l, int r, int L, int R, int val)
    {
        if (l > R || r < L)
            return;

        if (l >= L && r <= R)
        {
            tree[cur] += val;
        }
        else
        {
            update(cur * 2, l, (l + r) / 2, L, R, val);
            update(cur * 2 + 1, (l + r) / 2 + 1, r, L, R, val);
        }
    }

    int get_val(int cur, int l, int r, int idx)
    {
        if (idx < l || idx > r)
            return 0;

        int ret = tree[cur];
        if (l != r)
        {
            ret += get_val(cur * 2, l, (l + r) / 2, idx);
            ret += get_val(cur * 2 + 1, (l + r) / 2 + 1, r, idx);
        }
        return ret;
    }
};

int salary[500001], in[500001], out[500001];
vector<int> tree[500001];

void dfs(int cur, int parent)
{
    static int nth = 0;

    in[cur] = ++nth;
    for (int nxt : tree[cur])
    {
        if (in[nxt] == 0)
            dfs(nxt, cur);
    }

    out[cur] = nth;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N, M;
    cin >> N >> M;

    cin >> salary[1];
    for (size_t i = 2; i <= N; ++i)
    {
        int superior;
        cin >> salary[i] >> superior;
        tree[i].push_back(superior);
        tree[superior].push_back(i);
    }

    dfs(1, -1);

    SegmentTree diff(N);
    for (size_t i = 0; i < M; ++i)
    {
        char q;
        cin >> q;

        if (q == 'p')
        {
            int a, x;
            cin >> a >> x;
            if (in[a] != out[a])
                diff.update(1, 1, N, in[a] + 1, out[a], x);
        }
        else // q == 'u'
        {
            int a;
            cin >> a;
            cout << salary[a] + diff.get_val(1, 1, N, in[a]) << '\n';
        }
    }
}