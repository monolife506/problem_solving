#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n, s, r;
    cin >> n >> s >> r;

    vector<int> a(n, 1);
    int sum = s - n;
    for (int i = 0; i < n; ++i)
    {
        if (sum > s - r - 1)
        {
            a[i] += s - r - 1;
            sum -= s - r - 1;
        }
        else if (sum >= 1)
        {
            a[i] += sum;
            sum = 0;
        }

        cout << a[i] << " ";
    }

    cout << '\n';
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