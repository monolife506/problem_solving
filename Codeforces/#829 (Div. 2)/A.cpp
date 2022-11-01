#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    string dialog;
    cin >> dialog;

    int q_cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (dialog[i] == 'Q')
            ++q_cnt;
        else if (q_cnt > 0)
            --q_cnt;
    }

    cout << (q_cnt == 0 ? "Yes" : "No") << '\n';
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