// 1516번: 게임 개발
// 위상 정렬 연습 (DFS를 이용한 구현)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node
{
    int dur;
    vector<int> out;
};

void topological_sort(int cur, vector<Node> &graph, vector<bool> &visited, stack<int> &sorted)
{
    visited[cur] = true;
    for (int &nxt : graph[cur].out)
    {
        if (!visited[nxt])
            topological_sort(nxt, graph, visited, sorted);
    }
    sorted.push(cur);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, before, cnt;
    cin >> N;

    vector<Node> graph(N + 1);
    vector<int> ans(N + 1, 0);
    for (size_t i = 1; i <= N; i++)
    {
        cnt = 0;

        cin >> graph[i].dur >> before;
        while (before != -1)
        {
            graph[before].out.push_back(i);
            cnt++;

            cin >> before;
        }

        if (cnt == 0)
            ans[i] = graph[i].dur;
    }

    stack<int> sorted;
    vector<bool> visited(N + 1, false);
    for (size_t i = 1; i <= N; i++)
    {
        if (!visited[i])
            topological_sort(i, graph, visited, sorted);
    }
    while (!sorted.empty())
    {
        int cur = sorted.top();
        sorted.pop();

        for (int &nxt : graph[cur].out)
            ans[nxt] = max(ans[nxt], ans[cur] + graph[nxt].dur);
    }

    for (size_t i = 1; i <= N; i++)
        cout << ans[i] << '\n';
}