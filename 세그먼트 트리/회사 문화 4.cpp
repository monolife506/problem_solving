#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100000;

struct FenwickTree
{
    int *tree;
    size_t sz;

    FenwickTree(size_t n)
    {
        tree = new int[sz = n + 1];
        memset(tree, 0, sizeof(int) * sz);
    }

    ~FenwickTree() { delete[] tree; }

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

    void add(int i, int val)
    {
        while (i < sz)
        {
            tree[i] += val;
            i += (i & -i);
        }
    }
};

vector<int> tree[MAX_N + 1];
int in[MAX_N + 1], out[MAX_N + 1];

void dfs(int cur)
{
    static int nth = 0;

    in[cur] = ++nth;
    for (int child : tree[cur])
        dfs(child);

    out[cur] = nth;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n, m;
    cin >> n >> m;
    for (size_t child = 1; child <= n; ++child)
    {
        int parent;
        cin >> parent;
        if (parent != -1)
            tree[parent].push_back(child);
    }

    dfs(1);

    FenwickTree lower(n), upper(n);
    bool is_upper = false;
    for (size_t query = 0; query < m; query++)
    {
        int q;
        cin >> q;

        if (q == 1)
        {
            int i, w;
            cin >> i >> w;
            if (is_upper)
            {
                upper.add(in[i], w);
            }
            else
            {
                lower.add(in[i], w);
                if (out[i] + 1 <= n)
                    lower.add(out[i] + 1, -w);
            }
        }
        else if (q == 2)
        {
            int i;
            cin >> i;

            int upper_w = (in[i] > 1) ? upper.sum(out[i]) - upper.sum(in[i] - 1) : upper.sum(out[i]);
            int lower_w = lower.sum(in[i]);
            cout << upper_w + lower_w << '\n';
        }
        else // q == 3
        {
            is_upper = !is_upper;
        }
    }
}