#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    string T;
    cin >> T;

    ll ans = 0;
    vector<bool> flag(n + 1, true);
    for (ll i = 1; i <= n; ++i)
    {
        for (ll j = i; j <= n; j += i)
        {
            if (!flag[j])
                continue;
            if (T[j - 1] == '1')
                break;

            ans += i;
            flag[j] = false;
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

3 4

3 + 4


5 10 25

2 4 6 8 10
5
10

15 20 25

*/