#include <cstring>
#include <iostream>
using namespace std;
typedef pair<int, int> P;

int N, M, U, V, root[10001];
pair<P, int> edges[100000];

int find(int n)
{
    if (root[n] == -1)
        return n;
    else
        return root[n] = find(root[n]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
        root[b] = a;
}

bool f(int c)
{
    memset(root, -1, sizeof(root));
    for (int i = 0; i < M; ++i)
    {
        if (edges[i].second >= c)
            merge(edges[i].first.first, edges[i].first.second);
    }

    return find(U) == find(V);
}

int parametric_search()
{
    int l = 1, r = 1e9;
    int mid, ret;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (f(mid))
        {
            ret = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
        cin >> edges[i].first.first >> edges[i].first.second >> edges[i].second;

    cin >> U >> V;
    cout << parametric_search() << '\n';
}