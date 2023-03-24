#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a.begin(), a.end(), greater<int>());

    int start = -1;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] != a[i - 1])
        {
            start = i - 1;
            break;
        }
    }

    if (start == -1)
    {
        cout << "NO" << '\n';
    }
    else
    {
        cout << "YES" << '\n';
        for (int i = start; i < n; ++i)
            cout << a[i] << " ";
        for (int i = 0; i < start; ++i)
            cout << a[i] << " ";

        cout << '\n';
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

10 10

*/