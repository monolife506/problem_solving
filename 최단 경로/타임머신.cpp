// 11657번: 타임머신
// 벨만 포드 알고리즘

// 디익스트라보다 느림
// 간선의 가중치가 음수일때 사용

#include <iostream>
#include <vector>
using namespace std;

const int INF = INT32_MAX;
typedef pair<int, int> P;

// 벨만 포드 알고리즘 - 음의 루프가 존재한다면 True, 아니면 False 리턴
bool bellman(int start, const vector<vector<P>> &graph, vector<long long> &dist)
{
    int N = dist.size() - 1;
    dist[start] = 0;

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 1; j <= N; j++)
        {
            for (auto& node : graph[j])
            {
                int next = node.first;
                int w = node.second;

                if (dist[j] != INF && dist[next] > dist[j] + w)
                {
                    dist[next] = dist[j] + w;
                    if (i == N - 1) // 음의 루프 존재
                        return true;
                }      
            }
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<P>> graph(N + 1);
    vector<long long> dist(N + 1, INF);
    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back(P(B, C));
    }

    if (bellman(1, graph, dist))
        cout << -1;
    else
    {
        for (size_t i = 2; i <= N; i++)
            cout << ((dist[i] == INF) ? -1 : dist[i]) << '\n';
    }
}