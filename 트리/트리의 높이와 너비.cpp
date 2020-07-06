// 2250번: 트리의 높이와 너비

#include <iostream>
#include <cstring>
using namespace std;

struct Node
{
    int num;
    int depth;
    int parent;
    int left;
    int right;

    Node(int num = -1, int depth = 0, int parent = -1, int left = -1, int right = -1)
    {
        this->num = num;
        this->depth = depth;
        this->parent = parent;
        this->left = left;
        this->right = right;
    }
};

int N, rootNode;
int cnt = 1;
int maxDepth = 0;

Node tree[10001];
int depthMin[10001];
int depthMax[10001];

void findRoot(int cur)
{
    if (tree[cur].parent == -1)
        rootNode = cur;
    else
        findRoot(tree[cur].parent);
}

void inorder(int cur)
{
    if (tree[cur].left != -1)
    {
        tree[tree[cur].left].depth = tree[cur].depth + 1;
        inorder(tree[cur].left);
    }

    int curDepth = tree[cur].depth;
    maxDepth = max(curDepth, maxDepth);
    if (depthMax[curDepth] == 0)
        depthMax[curDepth] = cnt;
    else
        depthMax[curDepth] = max(depthMax[curDepth], cnt);
    if (depthMin[curDepth] == 0)
        depthMin[curDepth] = cnt;
    else
        depthMin[curDepth] = min(depthMin[curDepth], cnt);
    cnt++;

    if (tree[cur].right != -1)
    {
        tree[tree[cur].right].depth = tree[cur].depth + 1;
        inorder(tree[cur].right);
    }
}

int main()
{
    memset(depthMin, 0, sizeof(depthMin));
    memset(depthMax, 0, sizeof(depthMax));

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        int node, left, right;
        cin >> node >> left >> right;
        tree[node].left = left;
        tree[node].right = right;
        tree[left].parent = node;
        tree[right].parent = node;
    }

    findRoot(1);
    inorder(rootNode);
    int maxLevel = 0;
    int maxWidth = 0;
    for (size_t depth = 0; depth <= maxDepth; depth++)
    {
        if (maxWidth < 1 + depthMax[depth] - depthMin[depth])
        {
            maxLevel = depth + 1;
            maxWidth = 1 + depthMax[depth] - depthMin[depth];
        }
    }

    cout << maxLevel << " " << maxWidth;
}