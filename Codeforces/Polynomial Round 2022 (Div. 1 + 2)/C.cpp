#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> cache(n, 1);
    cout << cache[0] << " ";
    for (int i = 1; i < n - 1; ++i)
    {
        cache[i] = (s[i] != s[i - 1]) ? i + 1 : cache[i - 1];
        cout << cache[i] << " ";
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

/*

1 2 3 4 5 6 7

xxxx11

*/