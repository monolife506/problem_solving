// 4386번: 별자리 만들기

#include <iostream>
#include <iomanip>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
typedef pair<double, double> P;

P stars[100];
int root[100];

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
        return false;
    }
    return true;
}

double getDist(P &A, P &B)
{
    return sqrt(pow(A.first - B.first, 2) + pow(A.second - B.second, 2));
}

struct Edge
{
    int u, v;
    double w;
    Edge(int _u, int _v, double _w) : u(_u), v(_v), w(_w) {}
};

struct cmp
{
    bool operator()(const Edge &A, const Edge &B) { return A.w > B.w; }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<Edge, vector<Edge>, cmp> pq;
    memset(root, -1, sizeof(root));

    size_t N;
    cin >> N;
    for (size_t i = 0; i < N; i++)
        cin >> stars[i].first >> stars[i].second;

    for (size_t i = 0; i < N - 1; i++)
    {
        for (size_t j = i; j < N; j++)
        {
            if (i == j)
                continue;

            pq.push(Edge(i, j, getDist(stars[i], stars[j])));
        }
    }

    int nodeCnt = 0;
    double totalWeight = 0;
    while (nodeCnt < N - 1)
    {
        Edge cur = pq.top();
        pq.pop();

        if (!merge(cur.u, cur.v))
        {
            nodeCnt++;
            totalWeight += cur.w;
        }
    }

    cout << setprecision(3) << totalWeight;
}