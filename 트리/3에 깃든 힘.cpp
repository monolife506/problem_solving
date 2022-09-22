#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int dfs(int cur, int parent, vector<vector<int>> &tree, vector<vector<int>> &ans)
{
    static stack<int> nodes;

    if (tree[cur].size() == 1 && parent != -1)
    {
        nodes.push(cur);
        return 1;
    }

    int sum = 0;
    for (int nxt : tree[cur])
    {
        if (nxt == parent)
            continue;

        sum += dfs(nxt, cur, tree, ans);
    }

    nodes.push(cur);
    if (sum == 2)
    {
        vector<int> v;
        for (int i = 0; i < 3; ++i)
        {
            v.push_back(nodes.top());
            nodes.pop();
        }

        ans.push_back(v);

        return 0;
    }
    else
    {
        return sum + 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> tree(N + 1);
    vector<vector<int>> ans;

    for (int i = 0; i < N - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    if (dfs(1, -1, tree, ans) == 0)
    {
        cout << "S" << '\n';
        for (vector<int> &v : ans)
        {
            for (int num : v)
                cout << num << " ";

            cout << '\n';
        }
    }
    else
    {
        cout << "U" << '\n';
    }
}

/*

    1
    3
7        6
      5     2
      4    8 9
*/