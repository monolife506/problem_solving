#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

vector<P> tree[200001];
int A[200001], B[200001];
map<int, ll> cache[200001];
ll node_sum[200001];

void dp(int cur, int parent)
{
    for (P &p : tree[cur])
    {
        int nxt = p.first;
        int c = p.second;

        if (cache[cur].find(c) == cache[cur].end())
            cache[cur][c] = A[cur];

        if (nxt != parent)
        {
            dp(nxt, cur);
            cache[cur][c] += cache[nxt][c];
        }
    }
}

void dp2(int cur, int parent, int parent_c)
{
    if (parent != -1)
        cache[cur][parent_c] = cache[parent][parent_c];

    for (P &p : tree[cur])
    {
        int nxt = p.first;
        int c = p.second;

        if (nxt != parent)
            dp2(nxt, cur, c);
    }

    for (pair<const int, ll> &p : cache[cur])
        node_sum[cur] += p.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N - 1; ++i)
    {
        int v, w, c;
        cin >> v >> w >> c;
        tree[v].push_back({w, c});
        tree[w].push_back({v, c});
    }
    for (int i = 1; i <= N; ++i)
        cin >> A[i];
    for (int i = 1; i <= N; ++i)
        cin >> B[i];

    dp(1, -1);
    dp2(1, -1, -1);
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

5
1 2 1
2 3 1
3 4 2
4 5 2
1 2 3 4 5
1 2 3 4 5

6 6 6
    12 12 12

6 6 18 12 12

6 6 12 12 18
1 2 3 4 5

30 + 24 + 60 + 18 = 132
90 + 84 + 18 = 192

*/