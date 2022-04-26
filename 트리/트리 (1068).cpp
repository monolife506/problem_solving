#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[50];

int dfs(int cur, int deleted)
{
    if (cur == deleted)
        return 0;
    if (tree[cur].empty() || (tree[cur].size() == 1 && tree[cur][0] == deleted))
        return 1;

    int ret = 0;
    for (int child : tree[cur])
        ret += dfs(child, deleted);

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N;
    cin >> N;

    int root, deleted;
    for (size_t i = 0; i < N; ++i)
    {
        int parent;
        cin >> parent;

        if (parent == -1)
            root = i;
        else
            tree[parent].push_back(i);
    }

    cin >> deleted;
    cout << dfs(root, deleted) << '\n';
}