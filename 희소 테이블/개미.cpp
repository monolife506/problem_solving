#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> P;
const int MAX_N = 100000;
const int MAX_LOG_N = 17;

int N;
int energy[MAX_N + 1];
vector<P> tree[MAX_N + 1];

int parents[MAX_LOG_N + 1][MAX_N + 1];
int costs[MAX_LOG_N + 1][MAX_N + 1];

void dfs(int cur, int parent)
{
    parents[0][cur] = parent;
    for (P &p : tree[cur])
    {
        if (p.first == parent)
            costs[0][cur] = p.second;
        else
            dfs(p.first, cur);
    }
}

int query(int cur)
{
    int remaining = energy[cur];

    for (int i = MAX_LOG_N; i >= 0; i--)
    {
        int &parent = parents[i][cur];
        int &cost = costs[i][cur];

        if (parent == -1)
            continue;

        if (remaining >= cost)
        {
            cur = parent;
            remaining -= cost;
        }
    }

    return cur;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (size_t i = 1; i <= N; i++)
        cin >> energy[i];

    for (size_t i = 0; i < N - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    // 전처리
    memset(parents, -1, sizeof(parents));
    memset(costs, -1, sizeof(costs));
    dfs(1, -1);

    for (size_t i = 1; i <= MAX_LOG_N; i++)
    {
        for (size_t j = 1; j <= MAX_N; j++)
        {
            if (parents[i - 1][j] != -1)
            {
                parents[i][j] = parents[i - 1][parents[i - 1][j]];
                costs[i][j] = costs[i - 1][j] + costs[i - 1][parents[i - 1][j]];
            }
        }
    }

    // 쿼리
    for (size_t i = 1; i <= N; i++)
        cout << query(i) << '\n';
}