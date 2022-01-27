#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int depth;
    int parent = -1;
    vector<int> child;
};

int getRoot(vector<Node> &tree)
{
    for (size_t i = 1; i < tree.size(); i++)
        if (tree[i].parent == -1)
            return i;

    return -1; // error
}

void setDepth(int cur, int depth, vector<Node> &tree)
{
    tree[cur].depth = depth;
    for (int c : tree[cur].child)
        setDepth(c, depth + 1, tree);
}

int lca(int u, int v, vector<Node> &tree)
{
    if (tree[u].depth > tree[v].depth)
        swap(u, v);

    while (tree[u].depth != tree[v].depth)
        v = tree[v].parent;

    while (u != v)
    {
        u = tree[u].parent;
        v = tree[v].parent;
    }

    return u;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t T;
    cin >> T;
    for (size_t tc = 0; tc < T; tc++)
    {
        int N;
        cin >> N;

        vector<Node> tree(N + 1);
        for (size_t i = 0; i < N - 1; i++)
        {
            int A, B;
            cin >> A >> B;
            tree[A].child.push_back(B);
            tree[B].parent = A;
        }

        setDepth(getRoot(tree), 0, tree);

        int u, v;
        cin >> u >> v;
        cout << lca(u, v, tree) << '\n';
    }
}