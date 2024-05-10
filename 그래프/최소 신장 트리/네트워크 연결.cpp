#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int> t;

int root[1001];

int find(int n)
{
    return (root[n] == -1) ? n : root[n] = find(root[n]);
}

bool merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
        return false;

    root[b] = a;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(root, -1, sizeof(root));

    int N, M;
    cin >> N >> M;

    vector<t> e(M);
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        e[i] = {c, a, b};
    }

    int ans = 0, edge_cnt = 0;
    sort(e.begin(), e.end());
    for (int i = 0; i < M && edge_cnt < N - 1; ++i)
    {
        int &u = get<1>(e[i]);
        int &v = get<2>(e[i]);
        int &w = get<0>(e[i]);

        if (merge(u, v))
        {
            edge_cnt++;
            ans += w;
        }
    }

    cout << ans << '\n';
}