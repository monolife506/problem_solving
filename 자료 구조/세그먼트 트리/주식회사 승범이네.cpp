#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100001;

struct FenwickTree
{
    size_t n;
    int *tree;

    FenwickTree(size_t n) : n(n)
    {
        tree = new int[n + 1];
        memset(tree, 0, sizeof(int) * (n + 1));
    }

    ~FenwickTree() { delete[] tree; }

    int get_val(int i)
    {
        int ret = 0;
        while (i > 0)
        {
            ret += tree[i];
            i -= (i & -i);
        }
        return ret;
    }

    void update(int i, int val)
    {
        while (i <= n)
        {
            tree[i] += val;
            i += (i & -i);
        }
    }
};

vector<int> tree[MAX_N];
int in[MAX_N], out[MAX_N];

void dfs(int cur)
{
    static int nth = 0;

    in[cur] = ++nth;
    for (int nxt : tree[cur])
    {
        if (in[nxt] == 0)
            dfs(nxt);
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
    for (size_t i = 1; i <= N; ++i)
    {
        int parent;
        cin >> parent;
        if (parent != -1)
            tree[parent].push_back(i);
    }

    FenwickTree account(N);
    dfs(1);

    for (size_t q = 0; q < M; ++q)
    {
        int query;
        cin >> query;
        if (query == 1)
        {
            int i, w;
            cin >> i >> w;
            account.update(in[i], w);
            if (out[i] < N)
                account.update(out[i] + 1, -w);
        }
        else
        {
            int i;
            cin >> i;
            cout << account.get_val(in[i]) << '\n';
        }
    }
}