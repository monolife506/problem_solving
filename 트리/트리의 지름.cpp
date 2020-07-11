// 1167번: 트리의 지름
// 루트를 알 수 없다면 루트를 임의로 특정 => 여기서는 1번 노드

#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int maxValue = 0;
vector<P> tree[100001];
bool visited[100001] = {};

int dfs(int cur)
{
    visited[cur] = true;
    if (tree[cur].size() == 1 && cur != 1) // Leaf Node
        return 0;

    int first = 0;
    int second = 0;

    for (P &node : tree[cur])
    {
        int next = node.first;
        int w = node.second;
        if (!visited[next])
        {
            int child = dfs(next) + w;
            if (first < child)
            {
                second = first;
                first = child;
            }
            else if (second < child)
            {
                second = child;
            }
        }
    }

    maxValue = max(maxValue, first + second);
    return first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int V;
    cin >> V;
    for (size_t i = 0; i < V; i++)
    {
        int X, Y, W;
        cin >> X >> Y;
        while (Y != -1)
        {
            cin >> W;
            tree[X].push_back(P(Y, W));
            cin >> Y;
        }
    }

    int rootMax = dfs(1);
    cout << ((maxValue < rootMax) ? rootMax : maxValue);
}