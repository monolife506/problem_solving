// 13549번: 숨바꼭질 3

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int, int> P;

int N, K;
int dist[200001];

void dijkstra(int start)
{
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<bool> visited(200001, false);
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
        if (cur > 0 && (dist[cur - 1] > dist[cur] + 1 || dist[cur - 1] == -1))
        {
            dist[cur - 1] = dist[cur] + 1;
            if (!visited[cur - 1])
                pq.push(P(dist[cur - 1], cur - 1));
        }
        if (cur < 100000 && (dist[cur + 1] > dist[cur] + 1 || dist[cur + 1] == -1))
        {
            dist[cur + 1] = dist[cur] + 1;
            if (!visited[cur + 1])
                pq.push(P(dist[cur + 1], cur + 1));
        }
        if (cur < 100000 && (dist[cur * 2] > dist[cur] || dist[cur * 2] == -1))
        {
            dist[cur * 2] = dist[cur];
            if (!visited[cur * 2])
                pq.push(P(dist[cur * 2], cur * 2));
        }
    }
}

int main()
{
    memset(dist, -1, sizeof(dist));

    cin >> N >> K;
    dijkstra(N);
    cout << dist[K];
}