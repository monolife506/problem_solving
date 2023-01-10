#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int find(int n, vector<int> &root)
{
    return (root[n] < 0) ? n : root[n] = find(root[n], root);
}

void merge(int a, int b, vector<int> &root)
{
    a = find(a, root);
    b = find(b, root);
    if (a != b)
    {
        root[a] += root[b];
        root[b] = a;
    }
}

void solve()
{
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];

    vector<int> root(n, -1);
    for (int i = 0; i < n; ++i)
    {
        if (p[i] != i + 1)
            merge(i, p[i] - 1, root);
    }

    ll cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i == find(i, root))
            cnt += abs(root[i]) - 1;
    }

    ll ans = cnt + 1;
    for (int i = 0; i < n - 1; ++i)
    {
        if (find(i, root) == find(i + 1, root))
        {
            ans = cnt - 1;
            break;
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}

/*

https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/


ans == cnt - 1 || cnt + 1

1 ~ n

(k + 1, k) (k != 1 && k + 1 != n) -> cnt - 1
(n, n - 1) (idx[n - 1] == n) -> cnt - 1
(2, 1) (idx[2] == 1) -> cnt - 1

5
3 5 4 2 1

8
1 7 5 8 2 6 3 4




*/