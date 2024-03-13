#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= 26; ++i)
    {
        for (int j = 1; j <= 26; ++j)
        {
            for (int k = 1; k <= 26; ++k)
            {
                if (i + j + k == n)
                {
                    string ans;
                    ans.push_back('a' + (i - 1));
                    ans.push_back('a' + (j - 1));
                    ans.push_back('a' + (k - 1));
                    cout << ans << '\n';
                    return;
                }
            }
        }
    }
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