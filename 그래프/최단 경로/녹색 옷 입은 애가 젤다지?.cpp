#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> P;

const int INF = 987654321;

int dijkstra(int N, vector<vector<int>> &rupee)
{
    static int dy[] = {-1, 0, 1, 0};
    static int dx[] = {0, 1, 0, -1};

    vector<vector<int>> dist(N, vector<int>(N, INF));
    priority_queue<pair<int, P>, vector<pair<int, P>>, greater<pair<int, P>>> pq;

    dist[0][0] = rupee[0][0];
    pq.push({dist[0][0], {0, 0}});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();

        if (dist[y][x] < d)
            continue;

        for (int i = 0; i < 4; ++i)
        {
            int nxt_y = y + dy[i];
            int nxt_x = x + dx[i];
            if (nxt_y < 0 || nxt_y >= N || nxt_x < 0 || nxt_x >= N)
                continue;
            if (dist[nxt_y][nxt_x] <= dist[y][x] + rupee[nxt_y][nxt_x])
                continue;

            dist[nxt_y][nxt_x] = dist[y][x] + rupee[nxt_y][nxt_x];
            pq.push({dist[nxt_y][nxt_x], {nxt_y, nxt_x}});
        }
    }

    return dist[N - 1][N - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int idx = 1;
    while (true)
    {
        int N;
        cin >> N;

        if (N == 0)
            break;

        vector<vector<int>> rupee(N, vector<int>(N));
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
                cin >> rupee[i][j];
        }

        cout << "Problem " << idx++ << ": " << dijkstra(N, rupee) << '\n';
    }
}