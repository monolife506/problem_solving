#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 100000000;

struct Edge
{
    int x, y, cost;
    Edge(int _x, int _y, int _cost) : x(_x), y(_y), cost(_cost) {}
};

struct Info
{
    int x, y, state, cost;
    Info(int _x, int _y, int _state, int _cost) : x(_x), y(_y), state(_state), cost(_cost) {}
    bool operator<(const Info &I) const
    {
        return cost > I.cost;
    }
};

int N, M, X, Y, A, B, C;
int food[50][50];
int dist[50][50][1 << 4];
vector<Edge> graph[50][50];

void add_node(int x, int y, int nx, int ny, int cost)
{
    if (nx >= 0 && nx < N && ny >= 0 && ny < N)
        graph[x][y].push_back(Edge(nx, ny, cost));
}

void make_graph()
{
    static int knightX[4] = {-2, -1, 1, 2};
    static int knightY[4] = {-2, -1, 1, 2};

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < 4; k++)
                for (int l = 0; l < 4; l++)
                    if (abs(knightX[k]) != abs(knightY[l]))
                        add_node(i, j, i + knightX[k], j + knightY[l], A);

            for (int k = -N; k <= N; k++)
            {
                add_node(i, j, i + k, j + k, B);
                add_node(i, j, i + k, j - k, B);
                add_node(i, j, i + k, j, C);
                add_node(i, j, i, j + k, C);
            }
        }
    }
}

void dijkstra()
{
    for (size_t i = 0; i < 50; i++)
        for (size_t j = 0; j < 50; j++)
            for (size_t k = 0; k < 16; k++)
                dist[i][j][k] = MAX;

    priority_queue<Info> pq;
    dist[X][Y][0] = 0;
    pq.push(Info(X, Y, 0, dist[X][Y][0]));

    while (!pq.empty())
    {
        int x = pq.top().x;
        int y = pq.top().y;
        int state = pq.top().state;
        int cost = pq.top().cost;
        pq.pop();

        if (dist[x][y][state] < cost)
            continue;

        if (food[x][y] != 0 && ~state & 1 << food[x][y] - 1)
        {
            int nstate = state | 1 << (food[x][y] - 1);
            if (dist[x][y][nstate] > cost)
            {
                dist[x][y][nstate] = cost;
                pq.push(Info(x, y, nstate, dist[x][y][nstate]));
            }
        }

        for (Edge &edge : graph[x][y])
        {
            if (dist[edge.x][edge.y][state] > cost + edge.cost)
            {
                dist[edge.x][edge.y][state] = cost + edge.cost;
                pq.push(Info(edge.x, edge.y, state, dist[edge.x][edge.y][state]));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> A >> B >> C >> X >> Y >> M;
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        food[x][y] = i + 1;
    }

    make_graph();
    dijkstra();

    int ans = MAX;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            ans = min(ans, dist[i][j][(1 << M) - 1]);
        }
    }
    cout << ans;
}