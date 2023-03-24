#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int indegree = 0;
    vector<int> out;
};

int topological_sort(vector<Node> &graph, vector<int> &sorted)
{
    int N = graph.size() - 1;
    queue<int> Q;

    for (size_t i = 1; i <= N; i++)
    {
        if (graph[i].indegree == 0)
            Q.push(i);
    }
    for (size_t i = 1; i <= N; i++)
    {
        if (Q.empty())
            return -1;
        if (Q.size() > 1)
            return 0;

        int cur = Q.front();
        Q.pop();

        sorted.push_back(cur);
        for (int &nxt : graph[cur].out)
        {
            if (--graph[nxt].indegree == 0)
                Q.push(nxt);
        }
    }

    return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    size_t T, N, M, R, A, B;
    cin >> T;
    for (size_t tc = 0; tc < T; tc++)
    {
        vector<Node> graph;
        vector<int> rank, ans;
        vector<vector<bool>> isChanged;

        cin >> N;
        graph.resize(N + 1);
        rank.resize(N + 1);
        isChanged.resize(N + 1, vector<bool>(N + 1, false));
        for (size_t i = 1; i <= N; i++)
        {
            cin >> R;
            rank[R] = i;
        }

        cin >> M;
        for (size_t i = 0; i < M; i++)
        {
            cin >> A >> B;
            if (rank[A] < rank[B])
            {
                graph[B].out.push_back(A);
                graph[A].indegree++;
            }
            else
            {
                graph[A].out.push_back(B);
                graph[B].indegree++;
            }
            isChanged[A][B] = true;
        }

        for (size_t i = 1; i < N; i++)
        {
            for (size_t j = i + 1; j <= N; j++)
            {
                if (isChanged[i][j])
                    continue;

                if (rank[i] > rank[j])
                {
                    graph[j].out.push_back(i);
                    graph[i].indegree++;
                }
                else
                {
                    graph[i].out.push_back(j);
                    graph[j].indegree++;
                }
            }
        }

        switch (topological_sort(graph, ans))
        {
        case -1:
            cout << "IMPOSSIBLE";
            break;
        case 0:
            cout << "?";
            break;
        case 1:
            for (int num : ans)
                cout << num << " ";
            break;
        };
        cout << '\n';
    }
}