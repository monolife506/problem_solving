// 5639번: 이진 검색 트리

#include <iostream>
using namespace std;

struct Node
{
    int num;
    Node *left;
    Node *right;

    Node(int num = -1, Node *left = nullptr, Node *right = nullptr)
    {
        this->num = num;
        this->left = left;
        this->right = right;
    }
};

void insertNode(Node *curNode, Node *newNode)
{
    if (curNode->num > newNode->num)
    {
        if (curNode->left == nullptr)
            curNode->left = newNode;
        else
            insertNode(curNode->left, newNode);
    }
    else if (curNode->num < newNode->num)
    {
        if (curNode->right == nullptr)
            curNode->right = newNode;
        else
            insertNode(curNode->right, newNode);
    }
}

void postorder(Node *curNode)
{
    if (curNode->left != nullptr)
        postorder(curNode->left);
    if (curNode->right != nullptr)
        postorder(curNode->right);

    if (curNode->num != 0)
        cout << curNode->num << '\n';
}

int main()
{
    int num;
    Node *root = new Node(num);
    while (cin >> num)
    {
        if (root->num == -1)
            root->num = num;
        else
        {
            Node *newNode = new Node(num);
            insertNode(root, newNode);
        }
    }
    postorder(root);
}