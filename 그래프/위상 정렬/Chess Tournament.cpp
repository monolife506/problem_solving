#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, root[50001], indegree[50001];
vector<int> graph[50001];

int find(int n)
{
    if (root[n] == -1)
        return n;
    return root[n] = find(root[n]);
}

void merge(int a, int b)
{
    int root_a = find(a);
    int root_b = find(b);
    if (root_a != root_b)
        root[root_b] = root_a;
}

bool topologicalSort(vector<pair<int, int>> &input)
{
    for (size_t i = 0; i < input.size(); i++)
    {
        int K = find(input[i].first);
        int L = find(input[i].second);
        if (K == L)
            return false;

        graph[K].push_back(L);
        indegree[L]++;
    }

    queue<int> q;
    for (size_t i = 0; i < N; i++)
        if (indegree[i] == 0)
            q.push(i);

    for (size_t i = 0; i < N; i++)
    {
        if (q.empty())
            return false;

        int cur = q.front();
        q.pop();

        for (int next : graph[cur])
        {
            if (--indegree[next] == 0)
                q.push(next);
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(root, -1, sizeof(root));

    cin >> N >> M;

    vector<pair<int, int>> input;
    for (size_t i = 0; i < M; i++)
    {
        int K, L;
        char symbol;
        cin >> K >> symbol >> L;

        if (symbol == '=')
            merge(K, L);
        else if (symbol == '<')
            input.push_back(make_pair(K, L));
        else // symbol == '>'
            input.push_back(make_pair(L, K));
    }

    cout << (topologicalSort(input) ? "consistent" : "inconsistent") << '\n';
}