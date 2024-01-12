#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int root[3][100001];

int find(int i, int n)
{
    if (root[i][n] == 0)
        return n;
    return root[i][n] = find(i, root[i][n]);
}

void merge(int i, int a, int b)
{
    a = find(i, a);
    b = find(i, b);
    if (a != b)
        root[i][a] = b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m[3];
    cin >> n >> m[0] >> m[1] >> m[2];
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < m[i]; ++j)
        {
            int a, b;
            cin >> a >> b;
            merge(i, a, b);
        }
    }

    map<tuple<int, int, int>, vector<int>> mp;
    for (int i = 1; i <= n; ++i)
        mp[{find(0, i), find(1, i), find(2, i)}].push_back(i);

    vector<vector<int>> ans;
    for (auto &[t, v] : mp)
    {
        if (v.size() >= 2)
            ans.push_back(v);
    }

    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (auto v : ans)
    {
        for (int num : v)
            cout << num << ' ';
        cout << '\n';
    }
}

/*

(1 2 3) (4 5)
(1 2 3 4 5)
(1 4 5) (2 3)


*/