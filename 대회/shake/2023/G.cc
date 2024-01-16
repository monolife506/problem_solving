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

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    int ans = 0;
    for (int i = 0; i < n - 1; ++i)
        ans = max(ans, min(v[i], v[i + 1]));
    for (int i = 0; i < n - 2; ++i)
    {
        vector<int> tmp = {v[i], v[i + 1], v[i + 2]};
        sort(tmp.begin(), tmp.end());
        ans = max(ans, tmp[1]);
    }

    cout << ans << '\n';
}