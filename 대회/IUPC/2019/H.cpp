#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
const int INF = 40000000;

int V, M, J, S;
vector<P> graph[1001];
int distJ[1001], distS[1001];

void dijkstra(int start, int *dist)
{
    for (size_t i = 0; i < 1001; i++)
        dist[i] = INF;

    priority_queue<P, vector<P>, greater<P>> pq;
    dist[start] = 0;
    pq.push(P(dist[start], start));

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();

        if (dist[cur] < curDist)
            continue;

        for (const P &node : graph[cur])
        {
            int next = node.second;
            int nextDist = curDist + node.first;
            if (nextDist < dist[next])
            {
                dist[next] = nextDist;
                pq.push(P(dist[next], next));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> V >> M;
    for (size_t i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(P(c, b));
        graph[b].push_back(P(c, a));
    }

    cin >> J >> S;
    dijkstra(J, distJ);
    dijkstra(S, distS);

    int minTime = INF;
    for (size_t i = 1; i <= V; i++)
    {
        if (i == J || i == S)
            continue;

        minTime = min(distJ[i] + distS[i], minTime);
    }

    if (minTime == INF)
    {
        cout << -1;
    }
    else
    {
        vector<P> candidates;
        for (size_t i = 1; i <= V; i++)
        {
            if (i == J || i == S || distS[i] < distJ[i])
                continue;
            if (distJ[i] + distS[i] == minTime)
                candidates.push_back(P(distJ[i], i));
        }
        sort(candidates.begin(), candidates.end());

        if (!candidates.empty())
            cout << candidates[0].second;
        else
            cout << -1;
    }
}