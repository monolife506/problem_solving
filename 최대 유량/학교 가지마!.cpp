#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> P;

struct Edge
{
    int to, c, f = 0;
    Edge *reverse_edge = nullptr;
    explicit Edge(int to = -1, int c = 0) : to(to), c(c) {}

    int remain()
    {
        return c - f;
    }
    void add(int flow)
    {
        f += flow;
        reverse_edge->f -= flow;
    }
};

const int INF = 987654321;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

char tilemap[101][101];
vector<Edge *> network[20001];
int pre[20001];
Edge *path[20001];

int maximum_flow(int source, int sink)
{
    int ret = 0;

    while (true)
    {
        queue<int> q;
        q.push(source);
        memset(pre, -1, sizeof(pre));
        memset(path, (int)NULL, sizeof(path));

        while (!q.empty() && pre[sink] == -1)
        {
            int cur = q.front();
            q.pop();
            for (Edge *e : network[cur])
            {
                int &nxt = e->to;
                if (e->remain() > 0 && pre[nxt] == -1)
                {
                    q.push(nxt);
                    pre[nxt] = cur;
                    path[nxt] = e;
                }
            }
        }

        if (pre[sink] == -1)
            break;

        int flow = INF;
        for (int i = sink; i != source; i = pre[i])
            flow = min(flow, path[i]->remain());
        for (int i = sink; i != source; i = pre[i])
            path[i]->add(flow);

        ret += flow;
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K, H;
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> tilemap[i];

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < M; ++x)
        {
            if (tilemap[y][x] == '#')
                continue;
            if (tilemap[y][x] == 'K')
                K = 2 * (y * M + x) + 1;
            if (tilemap[y][x] == 'H')
                H = 2 * (y * M + x);

            int cur_in = 2 * (y * M + x);
            int cur_out = 2 * (y * M + x) + 1;

            Edge *e1 = new Edge(cur_out, 1);
            Edge *e2 = new Edge(cur_in, 0);
            e1->reverse_edge = e2;
            e2->reverse_edge = e1;
            network[cur_in].push_back(e1);
            network[cur_out].push_back(e2);

            for (int i = 0; i < 4; ++i)
            {
                int nxt_y = y + dy[i];
                int nxt_x = x + dx[i];
                if (nxt_y < 0 || nxt_y >= N || nxt_x < 0 || nxt_x >= M)
                    continue;
                if (tilemap[nxt_y][nxt_x] == '#')
                    continue;

                int nxt_in = 2 * (nxt_y * M + nxt_x);

                e1 = new Edge(nxt_in, INF);
                e2 = new Edge(cur_out, 0);
                e1->reverse_edge = e2;
                e2->reverse_edge = e1;
                network[cur_out].push_back(e1);
                network[nxt_in].push_back(e2);
            }
        }
    }

    int ans = maximum_flow(K, H);
    cout << (ans < N * M ? ans : -1) << '\n';
}