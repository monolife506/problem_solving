#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int indegree[1001];
vector<int> graph[1001];

bool topological_sort(vector<int> &sorted)
{
    queue<int> Q;
    for (size_t i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
            Q.push(i);
    }

    for (size_t i = 0; i < N; i++)
    {
        if (Q.empty())
            return false;

        int cur = Q.front();
        Q.pop();

        sorted.push_back(cur);
        for (int next : graph[cur])
        {
            if (--indegree[next] == 0)
                Q.push(next);
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (size_t i = 0; i < M; i++)
    {
        int K, from, to;
        cin >> K;

        if (K == 0)
            continue;

        cin >> from;
        for (size_t j = 1; j < K; j++)
        {
            cin >> to;
            graph[from].push_back(to);
            indegree[to]++;
            from = to;
        }
    }

    vector<int> sorted;
    if (topological_sort(sorted))
    {
        for (int num : sorted)
            cout << num << '\n';
    }
    else
    {
        cout << 0 << '\n';
    }
}