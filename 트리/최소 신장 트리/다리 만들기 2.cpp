#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int from, to, w;
    explicit Edge(int from, int to, int w) : from(from), to(to), w(w) {}
    bool operator<(const Edge &rhs) const { return w < rhs.w; }
};

int N, M, node_cnt, tilemap[11][11], visited[11][11], root[7];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int find(int n)
{
    if (root[n] == -1)
        return n;
    return root[n] = find(root[n]);
}

bool merge(int a, int b)
{
    int root_a = find(a);
    int root_b = find(b);
    if (root_a == root_b)
        return false;

    root[root_b] = root_a;
    return true;
}

void set_num(int y, int x, int num)
{
    visited[y][x] = true;
    tilemap[y][x] = num;
    for (size_t i = 0; i < 4; ++i)
    {
        int nxt_y = y + dy[i];
        int nxt_x = x + dx[i];
        if (nxt_y < 0 || nxt_y >= N || nxt_x < 0 || nxt_x >= M)
            continue;
        if (tilemap[nxt_y][nxt_x] == 1 && !visited[nxt_y][nxt_x])
            set_num(nxt_y, nxt_x, num);
    }
}

void modeling(vector<Edge> &edges)
{
    for (size_t i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < M; ++j)
        {
            if (tilemap[i][j] != 0 && !visited[i][j])
                set_num(i, j, ++node_cnt);
        }
    }

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < M; ++x)
        {
            if (tilemap[y][x] == 0)
                continue;

            for (size_t i = 0; i < 4; ++i)
            {
                int nxt_y = y + dy[i];
                int nxt_x = x + dx[i];
                if (nxt_y < 0 || nxt_y >= N || nxt_x < 0 || nxt_x >= M)
                    continue;
                if (tilemap[nxt_y][nxt_x] != 0)
                    continue;

                int w = 1;
                while (true)
                {
                    nxt_y += dy[i];
                    nxt_x += dx[i];
                    if (nxt_y < 0 || nxt_y >= N || nxt_x < 0 || nxt_x >= M)
                        break;
                    if (tilemap[nxt_y][nxt_x] == 0)
                    {
                        ++w;
                        continue;
                    }
                    if (w == 1)
                        break;

                    edges.push_back(Edge(tilemap[y][x], tilemap[nxt_y][nxt_x], w));
                    break;
                }
            }
        }
    }
}

int mst(vector<Edge> &edges)
{
    memset(root, -1, sizeof(root));
    int edge_cnt = 0;
    int total_w = 0;

    sort(edges.begin(), edges.end());
    for (int i = 0; edge_cnt < node_cnt - 1 && i < edges.size(); ++i)
    {
        if (merge(edges[i].from, edges[i].to))
        {
            ++edge_cnt;
            total_w += edges[i].w;
        }
    }

    return (edge_cnt == node_cnt - 1) ? total_w : -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (size_t i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < M; ++j)
            cin >> tilemap[i][j];
    }

    vector<Edge> edges;
    modeling(edges);
    cout << mst(edges) << '\n';
}