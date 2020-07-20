// 11779번: 최소비용 구하기 2

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int N, M;
int start, target, weight;
vector<P> graph[1001];

ll dist[1001];
int pre[1001];
bool visited[1001];

void dijkstra()
{
    priority_queue<P, vector<P>, greater<P>> pq;
    dist[start] = 0;
    pq.push(P(0, start));

    while (!pq.empty())
    {
        int cur;
        do
        {
            cur = pq.top().second;
            pq.pop();
        } while (!pq.empty() && visited[cur]);

        if (visited[cur])
            break;

        visited[cur] = true;
        for (auto &p : graph[cur])
        {
            int next = p.first;
            int weight = p.second;

            if (dist[cur] + weight < dist[next] || dist[next] == -1)
            {
                dist[next] = dist[cur] + weight;
                pre[next] = cur;

                if (!visited[next])
                    pq.push(P(dist[next], next));
            }
        }
    }
}

int main()
{
    memset(dist, -1, sizeof(dist));
    memset(pre, -1, sizeof(pre));

    cin >> N >> M;
    for (size_t i = 0; i < M; i++)
    {
        cin >> start >> target >> weight;
        graph[start].push_back(P(target, weight));
    }
    cin >> start >> target;

    dijkstra();
    cout << dist[target] << '\n';

    stack<int> path;
    while (target != -1)
    {
        path.push(target);
        target = pre[target];
    }

    cout << path.size() << '\n';
    while (!path.empty())
    {
        cout << path.top() << " ";
        path.pop();
    }
}