#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<int> even, odd;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;

        if (a % 2 == 0)
            even.push_back(a);
        else
            odd.push_back(a);
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    if (odd.size() % 2 == 0)
    {
        cout << 0 << '\n';
    }
    else
    {
        int ans = INT32_MAX;
        for (int i = 0; i < even.size(); ++i)
        {
            int num = even[i];
            int tmp = 0;
            while (num % 2 == 0)
            {
                num /= 2;
                tmp++;
            }

            ans = min(ans, tmp);
        }
        for (int i = 0; i < odd.size(); ++i)
        {
            int num = odd[i];
            int tmp = 0;
            while (num % 2 == 1)
            {
                num /= 2;
                tmp++;
            }

            ans = min(ans, tmp);
        }

        cout << ans << '\n';
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

/*

15 / 2 = 7

*/