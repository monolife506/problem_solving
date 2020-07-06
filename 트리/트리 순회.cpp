// 1991번: 트리 순회

#include <iostream>
using namespace std;

struct Node
{
    int left;
    int right;

    Node(int left = -1, int right = -1)
    {
        this->left = left;
        this->right = right;
    }
};

Node nodes[26];
void preorder(int cur)
{
    cout << (char)(cur + 'A');
    if (nodes[cur].left != -1)
        preorder(nodes[cur].left);
    if (nodes[cur].right != -1)
        preorder(nodes[cur].right);
}

void inorder(int cur)
{
    if (nodes[cur].left != -1)
        inorder(nodes[cur].left);
    cout << (char)(cur + 'A');
    if (nodes[cur].right != -1)
        inorder(nodes[cur].right);
}

void postorder(int cur)
{
    if (nodes[cur].left != -1)
        postorder(nodes[cur].left);
    if (nodes[cur].right != -1)
        postorder(nodes[cur].right);
    cout << (char)(cur + 'A');
}

int main()
{
    int N;
    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        char name, left, right;
        cin >> name >> left >> right;

        if (left != '.')
            nodes[name - 'A'].left = left - 'A';
        if (right != '.')
            nodes[name - 'A'].right = right - 'A';
    }

    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
}