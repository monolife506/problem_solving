#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int l = (n % 2 == 0) ? n / 2 - 1 : n / 2;
    int r = n / 2;

    int cnt = 0;
    while (l >= 0 && r < n)
    {
        if ((cnt % 2 == 0 && s[l] == s[r]) || (cnt == 1 && s[l] != s[r]))
        {
            l--;
            r++;
        }
        else if (cnt <= 1)
        {
            cnt++;
            l--;
            r++;
        }
        else
        {
            cout << "No" << '\n';
            return;
        }
    }

    cout << "Yes" << '\n';
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


011100

*/