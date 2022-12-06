#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<ll> s(n + 1), a(n + 1);
    for (int i = n - k + 1; i <= n; ++i)
        cin >> s[i];

    bool flag = true;

    ll max_a = INT32_MAX;
    for (int i = n - 1; i >= n - k + 1; --i)
    {
        a[i + 1] = s[i + 1] - s[i];
        if (i < n - 1 && a[i + 1] > a[i + 2])
        {
            flag = false;
            break;
        }
        else
        {
            max_a = a[i + 1];
        }
    }

    if (max_a * (n - k + 1) < s[n - k + 1])
        flag = false;

    cout << (flag ? "Yes" : "No") << '\n';
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

4 -> -6 (all < 1)

1
2
3

2
1
1

2 3

1

*/