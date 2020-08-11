// 1774번: 우주신과의 교감

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int root[1001];

struct Edge
{
    ll u, v;
    double w;
    Edge(ll _u, ll _v, double _w) : u(_u), v(_v), w(_w) {}

    bool operator<(const Edge &e) { return this->w < e.w; }
};

int find(int N)
{
    if (root[N] == -1)
        return N;
    return root[N] = find(root[N]);
}

bool merge(int U, int V)
{
    U = find(U);
    V = find(V);
    if (U != V)
    {
        root[U] = V;
        return true;
    }
    return false;
}

double getDist(P &A, P &B)
{
    return sqrt(pow(A.first - B.first, 2) + pow(A.second - B.second, 2));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(root, -1, sizeof(root));

    vector<P> stars;
    vector<Edge> edges;

    size_t N, M;
    cin >> N >> M;

    int edgeCnt = 0;
    double cost = 0;
    for (size_t i = 0; i < N; i++)
    {
        ll X, Y;
        cin >> X >> Y;
        stars.push_back(P(X, Y));
    }
    for (size_t i = 0; i < M; i++)
    {
        int U, V;
        cin >> U >> V;
        if (merge(U, V))
            edgeCnt++;
    }

    for (size_t i = 0; i < N - 1; i++)
        for (size_t j = i + 1; j < N; j++)
            edges.push_back(Edge(i + 1, j + 1, getDist(stars[i], stars[j])));

    sort(edges.begin(), edges.end());
    for (size_t i = 0; edgeCnt < N - 1; i++)
    {
        if (merge(edges[i].u, edges[i].v))
        {
            edgeCnt++;
            cost += edges[i].w;
        }
    }

    cout << fixed << setprecision(2) << cost;
}