#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

struct Edge
{
    int u, v, w;
    Edge(int u = -1, int v = -1, int w = -1) : u(u), v(v), w(w) {}

    bool operator<(const Edge &rhs) const
    {
        if (w != rhs.w)
            return w < rhs.w;
        else if (u != rhs.u)
            return u < rhs.u;
        else
            return v < rhs.v;
    }
};

const ll INF = 1e18;

int N, M;
Edge e[100000];
ll dist[2][50001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
        cin >> e[i].u >> e[i].v >> e[i].w;

    sort(e, e + M);

    int S, D;
    cin >> S >> D;

    fill_n(&dist[0][0], 2 * 50001, INF);
    unordered_set<int> s;

    dist[0][S] = 0;
    for (int i = 0; i < M; ++i)
    {
        dist[1][e[i].v] = min(dist[1][e[i].v], dist[0][e[i].u] + e[i].w);
        dist[1][e[i].u] = min(dist[1][e[i].u], dist[0][e[i].v] + e[i].w);
        s.insert(e[i].u);
        s.insert(e[i].v);

        if (i != M - 1 && e[i].w != e[i + 1].w)
        {
            while (!s.empty())
            {
                int cur = *s.begin();
                dist[0][cur] = min(dist[0][cur], dist[1][cur]);
                dist[1][cur] = INF;
                s.erase(cur);
            }
        }
    }

    while (!s.empty())
    {
        int cur = *s.begin();
        dist[0][cur] = min(dist[0][cur], dist[1][cur]);
        s.erase(cur);
    }

    if (dist[0][D] != INF)
        cout << dist[0][D] << '\n';
    else
        cout << "DIGESTA" << '\n';
}

/*

4 4
1 2 3
2 3 4
3 4 5
1 3 5
1 4

7 8
4 6 3
1 5 4
1 6 4
4 5 5
2 4 6
1 2 8
4 7 8
2 3 9
1 7

*/