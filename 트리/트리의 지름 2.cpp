// 1967번: 트리의 지름
// 지름은 루트나 리프 노드간의 거리 중의 최댓값이다.

#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

struct Node
{
    P parent = P(-1, 0); // 부모의 번호, 가중치
    vector<P> child;

    void setParent(int parent = -1, int weight = -1) { this->parent = P(parent, weight); }
    void addChild(int child, int weight)
    {
        this->child.push_back(P(child, weight));
    }
};

Node tree[10001];
int maxDist = 0;

int calculate(int cur)
{
    if (tree[cur].child.empty()) // Base Case
        return tree[cur].parent.second;

    int first = 0;
    int second = 0;
    for (P &child : tree[cur].child)
    {
        int returnVal = calculate(child.first);
        if (first < returnVal)
        {
            second = first;
            first = returnVal;
        }
        else if (second < returnVal)
        {
            second = returnVal;
        }
    }

    maxDist = max(maxDist, first + second);
    return first + tree[cur].parent.second;
}

int main()
{
    int N;
    cin >> N;
    for (size_t i = 0; i < N - 1; i++)
    {
        int parent, child, weight;
        cin >> parent >> child >> weight;
        tree[parent].addChild(child, weight);
        tree[child].setParent(parent, weight);
    }

    calculate(1);
    cout << maxDist;
}