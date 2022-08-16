#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int root[100001], A[100000];
P edge[100000];
bool flag[100000];

int find(int n)
{
    if (root[n] < 0)
        return n;
    else
        return root[n] = find(root[n]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        root[a] += root[b];
        root[b] = a;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(root, -1, sizeof(root));

    int N, M, Q;
    cin >> N >> M >> Q;
    for (int i = 0; i < M; ++i)
        cin >> edge[i].first >> edge[i].second;
    for (int i = 0; i < Q; ++i)
    {
        cin >> A[i];
        flag[--A[i]] = true;
    }

    ll ans = 0;
    for (int i = 0; i < M; ++i)
    {
        if (!flag[i])
            merge(edge[i].first, edge[i].second);
    }
    for (int i = Q - 1; i >= 0; --i)
    {
        int u = edge[A[i]].first;
        int v = edge[A[i]].second;

        if (find(u) == find(v))
            continue;

        ans += 1LL * abs(root[find(u)]) * abs(root[find(v)]);
        merge(u, v);
    }

    cout << ans << '\n';
}