#include <bits/stdc++.h>
#define endl '\n'
// #define FILE_RW
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int l[1000000], r[1000000];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> l[i] >> r[i];

    int ans = 1, cnt = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (l[i] > r[i + 1])
        {
            ans++;
            cnt = l[i + 1];
        }
        else if (cnt > r[i + 1])
        {
            ans++;
            cnt = l[i + 1];
        }
        else
        {
            cnt = max(cnt, l[i]);
        }
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef FILE_RW
    freopen("local.in", "r", stdin);
    freopen("local.out", "w", stdout);
#endif

    solve();
}
/*


13 15
5 8
6 14
3 7

3 4
2 3
1 2

*/