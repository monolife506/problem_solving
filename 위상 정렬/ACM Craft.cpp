// 1005번: ACM Craft
// 위상 정렬 연습 (Indegee의 개수를 이용한 구현)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int duration;
    int indegree = 0;
    vector<int> out;
};

int topological_sort(vector<Node> &graph, int W)
{
    vector<int> result(graph.size());
    queue<int> Q;

    for (size_t i = 1; i < graph.size(); i++)
    {
        if (graph[i].indegree == 0)
        {
            result[i] = graph[i].duration;
            Q.push(i);
        }
    }

    for (size_t i = 1; i < graph.size(); i++)
    {
        int cur = Q.front();
        Q.pop();

        for (int &nxt : graph[cur].out)
        {
            result[nxt] = max(result[nxt], result[cur] + graph[nxt].duration);
            if (--graph[nxt].indegree == 0)
                Q.push(nxt);
        }
    }

    return result[W];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, N, K, X, Y, W;
    cin >> T;

    for (size_t tc = 0; tc < T; tc++)
    {
        cin >> N >> K;
        vector<Node> graph(N + 1);
        for (size_t i = 1; i <= N; i++)
            cin >> graph[i].duration;
        for (size_t i = 0; i < K; i++)
        {
            cin >> X >> Y;
            graph[X].out.push_back(Y);
            graph[Y].indegree++;
        }
        cin >> W;

        cout << topological_sort(graph, W) << '\n';
    }
}