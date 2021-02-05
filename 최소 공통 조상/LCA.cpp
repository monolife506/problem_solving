// LCA: O(N)
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int depth;
    int parent;
    vector<int> edges;
};

Node tree[50001];

void set_parent(int cur)
{
    for (int child : tree[cur].edges)
    {
        if (child == tree[cur].parent)
            continue;

        tree[child].depth = tree[cur].depth + 1;
        tree[child].parent = cur;
        set_parent(child);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N;
    for (size_t i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].edges.push_back(v);
        tree[v].edges.push_back(u);
    }

    tree[1].depth = 0;
    tree[1].parent = -1;
    set_parent(1);

    cin >> M;
    for (size_t i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        while (u != v)
        {
            if (tree[u].depth < tree[v].depth)
            {
                v = tree[v].parent;
            }
            else if (tree[u].depth > tree[v].depth)
            {
                u = tree[u].parent;
            }
            else if (u != v)
            {
                u = tree[u].parent;
                v = tree[v].parent;
            }
        }

        cout << u << '\n';
    }
}