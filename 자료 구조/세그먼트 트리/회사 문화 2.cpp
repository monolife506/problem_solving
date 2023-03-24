#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

struct FenwickTree
{
    int *tree, sz;

    FenwickTree(int sz) : sz(sz)
    {
        tree = new int[sz + 1];
        memset(tree, 0, sizeof(tree));
    }

    ~FenwickTree() { delete[] tree; }

    void add(int i, int val)
    {
        while (i <= sz)
        {
            tree[i] += val;
            i += (i & -i);
        }
    }

    int sum(int i)
    {
        int ret = 0;
        while (i > 0)
        {
            ret += tree[i];
            i -= (i & -i);
        }

        return ret;
    }
};

const int MAX_N = 1e5;

vector<int> tree[MAX_N + 1];
int n, m, in[MAX_N + 1], out[MAX_N + 1];

void dfs(int cur)
{
    static int nth = 0;

    in[cur] = ++nth;
    for (int nxt : tree[cur])
        dfs(nxt);

    out[cur] = nth;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        int parent;
        cin >> parent;
        if (parent != -1)
            tree[parent].push_back(i);
    }

    dfs(1);
    FenwickTree fenwick_tree(n);
    for (int query = 0; query < m; ++query)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            int i, w;
            cin >> i >> w;

            fenwick_tree.add(in[i], w);
            if (out[i] < n)
                fenwick_tree.add(out[i] + 1, -w);
        }
        else
        {
            int i;
            cin >> i;
            cout << fenwick_tree.sum(in[i]) << '\n';
        }
    }
}