#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const string PI = "314159265358979323846264338327";

void solve()
{
    string n;
    cin >> n;
    for (int i = 0; i < n.length(); ++i)
    {
        if (n[i] != PI[i])
        {
            cout << i << '\n';
            return;
        }
    }

    cout << n.length() << '\n';
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