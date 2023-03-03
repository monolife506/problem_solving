#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int k;
    cin >> k;

    string s;
    cin >> s;

    string fb = "FBFFBFFBFBFFBFFBFBFFBFFB";
    cout << (fb.find(s) != string::npos ? "YES" : "NO") << '\n';
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

FBFFBFFB
FBFFBFFB

3 5 6 9 10 12 15
18 20 22 24 25 27 30



*/