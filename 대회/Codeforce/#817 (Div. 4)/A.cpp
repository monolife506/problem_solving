#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    string t = "Timur";
    sort(t.begin(), t.end());

    do
    {
        if (s == t)
        {
            cout << "YES" << '\n';
            return;
        }
    } while (next_permutation(t.begin(), t.end()));

    cout << "NO" << '\n';
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