#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

void solve()
{

    int n;
    cin >> n;

    ll ans = 0;
    vector<int> a(n), b(n);
    vector<int> frost, flame;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
        ans += b[i];
        if (a[i] == 0)
            flame.push_back(b[i]);
        else
            frost.push_back(b[i]);
    }

    sort(flame.begin(), flame.end(), greater<int>());
    sort(frost.begin(), frost.end(), greater<int>());

    if (flame.size() > frost.size())
    {
        for (int i = 0; i < frost.size(); ++i)
        {
            ans += flame[i];
            ans += frost[i];
        }
    }
    else if (flame.size() == frost.size())
    {
        ans *= 2;
        ans -= min(flame.back(), frost.back());
    }
    else
    {
        for (int i = 0; i < flame.size(); ++i)
        {
            ans += flame[i];
            ans += frost[i];
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

1 1 1
0

1 0 1 1

1 1 1
0 0

1 0 1 0 1

1 1 1
0 0 0

1 0 1 0 1 0


1 1 1 1
0 0 0 0

1 1 1 1
0 0 0

1 0 1 0 1 0 1
*/