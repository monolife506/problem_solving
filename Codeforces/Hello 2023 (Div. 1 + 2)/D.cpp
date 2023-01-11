#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int find(int n, vector<int> &root)
{
    return (root[n] == -1) ? n : root[n] = find(root[n], root);
}

void merge(int a, int b, vector<int> &root, vector<bool> &flag)
{
    a = find(a, root);
    b = find(b, root);
    if (a != b)
    {
        if (flag[b])
            flag[a] = true;

        root[b] = a;
    }
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> b(n);
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    int m;
    cin >> m;

    map<int, int> x;
    for (int i = 0; i < m; ++i)
    {
        int num;
        cin >> num;
        x[num]++;
    }

    map<int, vector<int>> idx;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] < b[i] || (a[i] > b[i] && x.find(b[i]) == x.end()))
        {
            cout << "NO" << '\n';
            return;
        }

        idx[b[i]].push_back(i);
    }

    vector<int> root(n, -1);
    vector<bool> flag(n, false);
    for (auto p : idx)
    {
        for (int i : idx[p.first])
        {
            if (a[i] > b[i])
                flag[find(i, root)] = true;

            if (i > 0 && b[i] >= b[i - 1])
                merge(i, i - 1, root, flag);
            if (i < n - 1 && b[i] >= b[i + 1])
                merge(i, i + 1, root, flag);
        }

        int cnt = 0;
        for (int i : idx[p.first])
        {
            int parent = find(i, root);
            if (flag[parent])
            {
                cnt++;
                flag[parent] = false;
            }
        }

        if (cnt > x[p.first])
        {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
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

7 3 1 5 3 2 2 6 8 10 1 1 5
5 3 1 5 3 2 2 5 8 5 1 1 5
8
5 3 5 4

1
5
3 4 4 2 3
2 4 4 2 2
1
2


*/