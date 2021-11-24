#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> P;
const int MAX_N = 100001;
const int MAX_LOG_N = 17;
const int INF = 1000001;

int N;
vector<P> tree[MAX_N];

int depths[MAX_N];
int parents[MAX_LOG_N][MAX_N];
int min_dist[MAX_LOG_N][MAX_N];
int max_dist[MAX_LOG_N][MAX_N];

void dfs(int cur, int parent, int depth)
{
    depths[cur] = depth;
    parents[0][cur] = parent;

    for (P &next : tree[cur])
    {
        if (next.first == parent)
        {
            min_dist[0][cur] = next.second;
            max_dist[0][cur] = next.second;
            continue;
        }

        dfs(next.first, cur, depth + 1);
    }
}

void precompute()
{
    for (size_t i = 0; i < MAX_LOG_N; i++)
    {
        for (size_t j = 0; j < MAX_N; j++)
        {
            parents[i][j] = -1;
            min_dist[i][j] = INF;
            max_dist[i][j] = -1;
        }
    }

    dfs(1, -1, 0);

    for (size_t i = 1; i < MAX_LOG_N; i++)
    {
        for (size_t j = 1; j < MAX_N; j++)
        {
            if (parents[i - 1][j] != -1)
            {
                parents[i][j] = parents[i - 1][parents[i - 1][j]];
                min_dist[i][j] = min(min_dist[i - 1][j], min_dist[i - 1][parents[i - 1][j]]);
                max_dist[i][j] = max(max_dist[i - 1][j], max_dist[i - 1][parents[i - 1][j]]);
            }
        }
    }
}

P query(int d, int e)
{
    int ret_min = INF;
    int ret_max = -1;

    if (depths[d] < depths[e])
        swap(d, e);

    for (int i = MAX_LOG_N - 1; i >= 0; i--)
    {
        if (depths[d] - depths[e] >= (1 << i))
        {
            ret_min = min(ret_min, min_dist[i][d]);
            ret_max = max(ret_max, max_dist[i][d]);
            d = parents[i][d];
        }
    }

    if (d == e)
        return {ret_min, ret_max};

    for (int i = MAX_LOG_N - 1; i >= 0; i--)
    {
        if (parents[i][d] != -1 && parents[i][d] != parents[i][e])
        {
            ret_min = min(ret_min, min(min_dist[i][d], min_dist[i][e]));
            ret_max = max(ret_max, max(max_dist[i][d], max_dist[i][e]));
            d = parents[i][d];
            e = parents[i][e];
        }
    }

    ret_min = min(ret_min, min(min_dist[0][d], min_dist[0][e]));
    ret_max = max(ret_max, max(max_dist[0][d], max_dist[0][e]));

    return {ret_min, ret_max};
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;

    cin >> N;
    for (size_t i = 0; i < N - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].push_back(P(b, c));
        tree[b].push_back(P(a, c));
    }

    precompute();

    cin >> k;
    for (size_t i = 0; i < k; i++)
    {
        int d, e;
        cin >> d >> e;
        P ans = query(d, e);
        cout << ans.first << " " << ans.second << '\n';
    }
}