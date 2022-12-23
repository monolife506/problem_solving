#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a.begin() + 1, a.end());
    for (int i = 1; i < n; ++i)
    {
        if (a[0] < a[i])
        {
            if ((a[0] + a[i]) % 2 == 0)
                a[0] = (a[0] + a[i]) / 2;
            else
                a[0] = (a[0] + a[i]) / 2 + 1;
        }
    }

    cout << a[0] << '\n';
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


3 4 4 6 7 8 10
4 3 4 6 7 8 10
5 3 4 5 7 8 10
6 3 4 5 6 8 10


*/