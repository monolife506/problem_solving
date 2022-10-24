#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    int cnt = 0;
    int max_cnt = 0;

    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        int a;
        cin >> a;
        while (a % 2 == 0)
        {
            ++cnt;
            a /= 2;
        }

        int idx = i;
        int num = 0;
        while (idx % 2 == 0)
        {
            ++max_cnt;
            ++num;
            idx /= 2;
        }

        if (num != 0)
            v.push_back(num);
    }

    sort(v.begin(), v.end());
    if (cnt + max_cnt >= n)
    {
        int sum = cnt;
        int ans = 0;
        for (int i = v.size() - 1; i >= 0; --i)
        {
            if (sum + v[i] <= n)
            {
                sum += v[i];
                ++ans;
            }
        }

        cout << ans << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solve();
}

/*


2 * 5
7
2 * 7
2 * 9
3
5

2 - 3

1
2
1
3
1
2

3
2
2
1
1
1

*/