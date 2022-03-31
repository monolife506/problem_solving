// 15900번: 나무 탈출

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int leafDist = 0;

vector<int> tree[500001];
bool visited[500001];

void bfs(int start)
{
    queue<P> Q;
    Q.push(P(start, 0));

    while (!Q.empty())
    {
        int curNum = Q.front().first;
        int curDist = Q.front().second;
        Q.pop();

        bool isLeaf = true;
        visited[curNum] = true;
        for (int &node : tree[curNum])
        {
            if (!visited[node])
            {
                isLeaf = false;
                Q.push(P(node, curDist + 1));
            }
        }

        if (isLeaf)
            leafDist += curDist;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }

    bfs(1);
    cout << ((leafDist % 2 == 0) ? "No" : "Yes");
}

// 리프 노드들의 거리의 총합이
// 짝수: No
// 홀수: Yes