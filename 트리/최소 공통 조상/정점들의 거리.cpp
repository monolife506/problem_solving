#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 40000;
const int MAX_LOG_N = 15;

// first: node 번호, second: 거리
vector<pair<int, int>> tree[MAX_N + 1];

int N;
int depths[MAX_N + 1]; // i번 node의 depth
int dists[MAX_N + 1];  // i번 node와 root 사이의 거리

// tree의 parent에 대한 sparse table
int parents[MAX_LOG_N + 1][MAX_N + 1];

void dfs(int cur, int parent, int depth, int dist)
{
    parents[0][cur] = parent;
    dists[cur] = dist;
    depths[cur] = depth;

    for (pair<int, int> &p : tree[cur])
    {
        if (p.first != parent)
            dfs(p.first, cur, depth + 1, p.second + dist);
    }
}

void precomputation()
{
    memset(parents, -1, sizeof(parents));
    dfs(1, -1, 0, 0); // 1을 root로 정보 채우기

    for (size_t i = 1; i <= MAX_LOG_N; i++)
    {
        for (size_t j = 1; j <= MAX_N; j++)
        {
            if (parents[i - 1][j] != -1)
                parents[i][j] = parents[i - 1][parents[i - 1][j]];
        }
    }
}

int query(int u, int v)
{
    int ret = dists[u] + dists[v];

    if (depths[u] < depths[v])
        swap(u, v);

    for (int i = MAX_LOG_N; i >= 0; i--)
    {
        if (depths[u] - depths[v] >= (1 << i))
            u = parents[i][u];
    }

    if (u != v)
    {
        for (int i = MAX_LOG_N; i >= 0; i--)
        {
            if (parents[i][u] != -1 && parents[i][u] != parents[i][v])
            {
                u = parents[i][u];
                v = parents[i][v];
            }
        }

        ret -= 2 * dists[parents[0][u]];
    }
    else
        ret -= 2 * dists[u];

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int M;

    cin >> N;
    for (size_t i = 0; i < N - 1; i++)
    {
        int u, v, dist;
        cin >> u >> v >> dist;
        tree[u].push_back(make_pair(v, dist));
        tree[v].push_back(make_pair(u, dist));
    }

    precomputation();

    cin >> M;
    for (size_t i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << query(u, v) << '\n';
    }
}

/*
Sparse Table을 이용해 LCA 구현하기
*/