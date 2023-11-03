#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, h[200001], dp[200001];

int f(int cur)
{
    if (cur > n)
        return 0;
    if (dp[cur] != -1)
        return dp[cur];

    return dp[cur] = f(cur + h[cur] + 1) + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill_n(&dp[0], 200001, -1);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> h[i];

    for (int i = 1; i <= n; ++i)
        cout << f(i) << ' ';

    cout << '\n';
}