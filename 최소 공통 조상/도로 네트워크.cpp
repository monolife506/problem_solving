#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> P;
const int MAX_N = 100001;
const int MAX_LOG_N = 17;
const int INF = 1000001;

struct Entry
{
    int next = -1;
    int min_d = INF;
    int max_d = -1;
};

int N;
vector<P> tree[MAX_N];

int depths[MAX_N];
Entry table[MAX_LOG_N][MAX_N];

void dfs(int cur, int parent, int depth)
{
    depths[cur] = depth;
    table[0][cur].next = parent;

    for (P &next : tree[cur])
    {
        if (next.first == parent)
        {
            table[0][cur].min_d = next.second;
            table[0][cur].max_d = next.second;
            continue;
        }

        dfs(next.first, cur, depth + 1);
    }
}

void precompute()
{
    dfs(1, -1, 0);

    for (size_t i = 1; i <= MAX_LOG_N; i++)
    {
        for (size_t j = 1; j <= MAX_N; j++)
        {
            if (table[i - 1][j].next != -1)
            {
                table[i][j].next = table[i - 1][table[i - 1][j].next].next;
                table[i][j].min_d = min(table[i - 1][j].min_d, table[i - 1][table[i - 1][j].next].min_d);
                table[i][j].max_d = max(table[i - 1][j].max_d, table[i - 1][table[i - 1][j].next].max_d);
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

    for (int i = MAX_LOG_N; i >= 0; i--)
    {
        if (depths[d] - depths[e] >= (1 << i))
        {
            cout << " (" << table[i][d].min_d << " " << table[i][d].max_d << ") ";
            ret_min = min(ret_min, table[i][d].min_d);
            ret_max = max(ret_max, table[i][d].max_d);
            d = table[i][d].next;
        }
    }

    if (d == e)
        return {ret_min, ret_max};

    for (int i = MAX_LOG_N; i >= 0; i--)
    {
        if (table[i][d].next != -1 && table[i][d].next != table[i][e].next)
        {
            ret_min = min(ret_min, table[i][d].min_d);
            ret_max = max(ret_max, table[i][d].max_d);
            cout << " (" << table[i][d].min_d << " " << table[i][d].max_d << ") ";
            d = table[i][d].next;
            ret_min = min(ret_min, table[i][e].min_d);
            ret_max = max(ret_max, table[i][e].max_d);
            cout << " (" << table[i][e].min_d << " " << table[i][e].max_d << ") ";
            e = table[i][e].next;
        }
    }

    ret_min = min(ret_min, table[0][d].min_d);
    ret_max = max(ret_max, table[0][d].max_d);
    cout << " (" << table[0][d].min_d << " " << table[0][d].max_d << ") ";
    ret_min = min(ret_min, table[0][e].min_d);
    ret_max = max(ret_max, table[0][e].max_d);
    cout << " (" << table[0][e].min_d << " " << table[0][e].max_d << ") ";

    return {ret_min, ret_max};
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

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
        cout << '\n'
             << ans.first << " " << ans.second << '\n';
    }
}