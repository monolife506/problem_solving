#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    int alice = 0, bob = 0, turn = 0;
    while (n > 0)
    {
        turn++;

        if ((turn / 2) % 2 == 0)
        {
            alice += min(turn, n);
            n = max(0, n - turn);
        }
        else
        {
            bob += min(turn, n);
            n = max(0, n - turn);
        }
    }

    cout << alice << " " << bob << '\n';
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