#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> P;
const int INF = 200000000;

struct Node {
    char type = '?';
    int dist = INF;
    vector<P> edge;
};

int N, M, J, K;
Node graph[5001];

void dijkstra()
{
    priority_queue<P, vector<P>, greater<P>> pq;
    graph[J].dist = 0;
    pq.push(P(graph[J].dist, J));

    while (!pq.empty()) {
        int cur = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();

        if (graph[cur].dist < curDist)
            continue;

        for (const P& node : graph[cur].edge) {
            int next = node.second;
            int nextDist = curDist + node.first;
            if (nextDist < graph[next].dist) {
                graph[next].dist = nextDist;
                pq.push(P(graph[next].dist, next));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> J >> K;
    for (size_t i = 0; i < K; i++) {
        int num;
        cin >> num;
        graph[num].type = 'A';
    }
    for (size_t i = 0; i < K; i++) {
        int num;
        cin >> num;
        graph[num].type = 'B';
    }
    for (size_t i = 0; i < M; i++) {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        graph[X].edge.push_back(P(Z, Y));
        graph[Y].edge.push_back(P(Z, X));
    }

    dijkstra();

    int distA = INF;
    int distB = INF;
    for (size_t i = 1; i <= N; i++) {
        if (graph[i].dist != INF) {
            if (graph[i].type == 'A')
                distA = min(distA, graph[i].dist);
            else if (graph[i].type == 'B')
                distB = min(distB, graph[i].dist);
        }
    }

    if (distA == INF && distB == INF)
        cout << -1;
    else {
        if (distA <= distB) {
            cout << 'A' << '\n';
            cout << distA;
        } else {
            cout << 'B' << '\n';
            cout << distB;
        }
    }
}