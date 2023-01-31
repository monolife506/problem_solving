#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> idx[2];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        idx[a[i] % 2].push_back(i + 1);
    }

    if (idx[1].size() >= 3)
    {
        cout << "YES" << '\n';
        cout << idx[1][0] << " " << idx[1][1] << " " << idx[1][2] << '\n';
    }
    else if (idx[0].size() >= 2 && idx[1].size() >= 1)
    {
        cout << "YES" << '\n';
        cout << idx[0][0] << " " << idx[0][1] << " " << idx[1][0] << '\n';
    }
    else
    {
        cout << "NO" << '\n';
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

홀홀홀
짝짝홀

*/