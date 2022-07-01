#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[100001];

int cache[100001];

int dp(int cur, int parent)
{
    int &ret = cache[cur];
    for (int nxt : tree[cur])
    {
        if (nxt != parent)
            ret = max(ret, dp(nxt, cur) + 1);
    }

    return ret;
}

int ans(int cur, int parent, int D)
{
    int ret = 1;
    for (int nxt : tree[cur])
    {
        if (nxt != parent && cache[nxt] >= D)
            ret += ans(nxt, cur, D);
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, S, D;
    cin >> N >> S >> D;
    for (int i = 0; i < N - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    dp(S, -1);
    cout << 2 * (ans(S, -1, D) - 1) << '\n';
}
