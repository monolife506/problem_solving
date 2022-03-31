#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N, M;
vector<int> graph[100000];
vector<int> graph_reverse[100000];

stack<int> S;
bool visited[100000];
bool visited_reverse[100000];

int SCC_size = 0;
int SCC[100000];
int SCC_indegree[100000];

void DFS(int cur)
{
    visited[cur] = true;
    for (int next : graph[cur])
    {
        if (!visited[next])
            DFS(next);
    }

    S.push(cur);
}

void DFS_reverse(int cur, int idx)
{
    visited_reverse[cur] = true;
    SCC[cur] = idx;
    for (int next : graph_reverse[cur])
    {
        if (!visited_reverse[next])
            DFS_reverse(next, idx);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (size_t i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        graph_reverse[B].push_back(A);
    }

    for (size_t i = 0; i < N; i++)
    {
        if (!visited[i])
            DFS(i);
    }

    while (!S.empty())
    {
        int cur = S.top();
        S.pop();

        if (!visited_reverse[cur])
            DFS_reverse(cur, SCC_size++);
    }

    for (size_t cur = 0; cur < N; cur++)
    {
        for (int next : graph[cur])
        {
            if (SCC[cur] != SCC[next])
                SCC_indegree[SCC[next]]++;
        }
    }

    int result = 0;
    for (size_t i = 0; i < SCC_size; i++)
    {
        if (SCC_indegree[i] == 0)
            result++;
    }
    cout << result;
}