#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a.begin(), a.end());

    int l = 0;
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ++cnt;
        if (a[l] + m <= a[i])
        {
            while (a[l] + m <= a[i])
            {
                l++;
                --cnt;
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans << '\n';
}