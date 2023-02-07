#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    int alice[2] = {}, bob[2] = {};
    int cnt = 0, turn = 1;
    for (int i = 1; i <= n; ++i)
    {
        if ((turn / 2) % 2 == 0)
            alice[!(i % 2)]++;
        else
            bob[!(i % 2)]++;

        cnt++;
        if (cnt == turn)
        {
            cnt = 0;
            turn++;
        }
    }

    cout << alice[0] << " " << alice[1] << " " << bob[0] << " " << bob[1] << '\n';
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