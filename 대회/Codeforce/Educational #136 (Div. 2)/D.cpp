#include <iostream>
#include <vector>
using namespace std;

int n, k, cnt;
vector<vector<int>> tree;

int dfs(int cur, int max_h, vector<vector<int>> &tree)
{
    int height = 0;
    for (int nxt : tree[cur])
    {
        int subtree_height = dfs(nxt, max_h, tree);
        if (subtree_height == -1)
        {
            continue;
        }
        else if (subtree_height == max_h - 1 && cur != 1)
        {
            ++cnt;
            continue;
        }
        else
        {
            height = max(height, subtree_height + 1);
        }
    }

    return height;
}

bool f(int h)
{
    cnt = 0;
    dfs(1, h, tree);
    return (cnt <= k);
}

int parametric_search()
{
    int l = 1, r = 200000;
    int mid, ret = -1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (f(mid))
        {
            ret = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return ret;
}

void solve()
{
    cin >> n >> k;

    tree.clear();
    tree.resize(n + 1, vector<int>());

    for (int i = 2; i <= n; ++i)
    {
        int p;
        cin >> p;
        tree[p].push_back(i);
    }

    cout << parametric_search() << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solve();
}
