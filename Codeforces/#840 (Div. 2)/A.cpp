#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> cnt(2, vector<int>(10, 0));
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;

        bitset<10> b(a);
        for (int i = 0; i < 10; ++i)
            cnt[b[i]][i]++;
    }

    int max_a = 0;
    for (int i = 0; i < 10; ++i)
    {
        if (cnt[1][i] != 0)
            max_a += (int)pow(2, i);
    }

    int min_a = 0;
    for (int i = 0; i < 10; ++i)
    {
        if (cnt[0][i] == 0)
            min_a += (int)pow(2, i);
    }

    cout << max_a - min_a << '\n';
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