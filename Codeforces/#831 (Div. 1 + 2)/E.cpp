#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, cache[2][100001];
vector<int> tree[100001];

void dfs(int cur)
{
    if (tree[cur].empty())
    {
        cache[0][cur] = 0;
        cache[1][cur] = 1;
        return;
    }

    cache[0][cur] = 0;
    cache[1][cur] = 1;
    for (int c : tree[cur])
    {
        dfs(c);
        cache[0][cur] += max(cache[0][c], cache[1][c]);
        cache[1][cur] = max(cache[1][cur], cache[1][c] + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 2; i <= n; ++i)
    {
        int p;
        cin >> p;
        tree[p].push_back(i);
    }

    dfs(1);
    cout << max(cache[0][1], cache[1][1]) << '\n';
}

/*

7
1 2 1 4 1 6

*/