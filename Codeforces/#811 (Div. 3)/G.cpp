#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int> tp;

int d[200001];
ll A[200001], B[200001];

void dfs(int cur, int depth, ll a_sum, ll b_sum,
         vector<vector<tp>> &tree, vector<vector<int>> &table)
{
    d[cur] = depth;
    A[cur] = a_sum;
    B[cur] = b_sum;

    for (tp &t : tree[cur])
    {
        int &nxt = get<0>(t);
        int &a = get<1>(t);
        int &b = get<2>(t);

        table[0][nxt] = cur;
        dfs(nxt, depth + 1, a_sum + a, b_sum + b, tree, table);
    }
}

bool f(int cur, int m, vector<vector<int>> &table)
{
    int child = cur;
    for (int i = 20; i >= 0; i--)
    {
        if (m >= (1 << i))
        {
            m -= (1 << i);
            child = table[i][child];
        }
    }

    return B[child] <= A[cur];
}

int parametric_search(int cur, vector<vector<int>> &table)
{
    int l = 0;
    int r = d[cur];
    int ret = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (f(cur, mid, table))
        {
            ret = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return d[cur] - ret;
}

void solve()
{

    int n;
    cin >> n;

    vector<vector<tp>> tree(n + 1);
    vector<vector<int>> table(21, vector<int>(n + 1, -1));
    for (int i = 2; i <= n; ++i)
    {
        int p, a, b;
        cin >> p >> a >> b;
        tree[p].push_back({i, a, b});
    }

    dfs(1, 0, 0, 0, tree, table);
    for (int i = 1; i <= 20; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (table[i - 1][j] != -1)
                table[i][j] = table[i - 1][table[i - 1][j]];
        }
    }

    for (int i = 2; i <= n; ++i)
        cout << parametric_search(i, table) << " ";

    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}