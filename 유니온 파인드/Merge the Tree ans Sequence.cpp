#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

struct Edge
{
    int v, w, c;
    Edge(int v = -1, int w = -1, int c = -1) : v(v), w(w), c(c) {}
};

vector<int> tree[200001];
Edge e[200001];
int A[200001], B[200001];

int root[200001];
ll root_sum[200001], node_sum[200001];

int find(int n)
{
    return (root[n] == -1) ? n : root[n] = find(root[n]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
        root[b] = a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(root, -1, sizeof(root));

    int N;
    cin >> N;
    for (int i = 1; i <= N - 1; ++i)
    {
        cin >> e[i].v >> e[i].w >> e[i].c;
        tree[e[i].v].push_back(i);
        tree[e[i].w].push_back(i);
    }
    for (int i = 1; i <= N; ++i)
        cin >> A[i];
    for (int i = 1; i <= N; ++i)
        cin >> B[i];

    for (int i = 1; i <= N; ++i)
    {
        sort(tree[i].begin(), tree[i].end(),
             [](int &lhs, int &rhs) -> bool
             { return e[lhs].c < e[rhs].c; });

        for (int j = 1; j < tree[i].size(); ++j)
        {
            if (e[tree[i][j - 1]].c == e[tree[i][j]].c)
                merge(tree[i][j - 1], tree[i][j]);
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        sort(tree[i].begin(), tree[i].end(),
             [](int &lhs, int &rhs) -> bool
             { return find(lhs) < find(rhs); });

        root_sum[find(tree[i][0])] += A[i];
        for (int j = 1; j < tree[i].size(); ++j)
        {
            if (e[tree[i][j - 1]].c != e[tree[i][j]].c)
                root_sum[find(tree[i][j])] += A[i];
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        node_sum[i] += root_sum[find(tree[i][0])];
        for (int j = 1; j < tree[i].size(); ++j)
        {
            if (e[tree[i][j - 1]].c != e[tree[i][j]].c)
                node_sum[i] += root_sum[find(tree[i][j])];
        }
    }

    sort(node_sum + 1, node_sum + N + 1);
    sort(B + 1, B + N + 1);

    ll min_val = 0, max_val = 0;
    for (int i = 1; i <= N; ++i)
    {
        min_val += node_sum[i] * B[N - (i - 1)];
        max_val += node_sum[i] * B[i];
    }

    cout << min_val << '\n'
         << max_val << '\n';
}

/*

4
1 2 1
2 3 2
3 4 3
1 2 3 4
1 2 3 4

3 3
  5 5
    7 7

3 7 8 12
1 2 3 4

12 + 16 + 21 + 12 = 61
3 + 14 + 24 + 48 = 89

4
1 2 1
1 3 2
1 4 3
1 2 3 4
1 2 3 4

3 3
4   4
5     5

3 4 5 12
1 2 3 4

3 + 8 + 15 + 48 = 74
12 + 12 + 10 + 12 = 46

DFS -> TLE???
Union-Find -> 간선들에 대해 Union-Find 연산

*/