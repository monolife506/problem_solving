#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

typedef pair<int, int> P;
const int MAX_V = 100000;

int V, E;
vector<int> graph[MAX_V + 1];

int counter = 0;
int discovered[MAX_V + 1]; // dfs 스패닝 트리의 순회 순서 기록
set<P> bridge;

// cur에서 parent로 항하는 간선을 제외하고 cur에서 도달할 수 있는 노드의 최소 counter return
int dfs(int cur, int parent)
{
    discovered[cur] = counter++;

    int ret = discovered[cur];
    for (int &next : graph[cur])
    {
        if (next == parent)
            continue;

        if (discovered[next] == -1) // 트리 간선
        {
            int subtree = dfs(next, cur);
            if (subtree > discovered[cur])
                bridge.insert(P(min(cur, next), max(cur, next)));
            ret = min(ret, subtree);
        }
        else
        {
            ret = min(ret, discovered[next]);
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(discovered, -1, sizeof(discovered));

    cin >> V >> E;
    for (size_t i = 0; i < E; i++)
    {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    for (size_t i = 1; i <= V; i++)
    {
        if (discovered[i] == -1)
            dfs(i, -1);
    }

    cout << bridge.size() << '\n';
    for (auto it = bridge.begin(); it != bridge.end(); ++it)
        cout << (*it).first << " " << (*it).second << '\n';
}
