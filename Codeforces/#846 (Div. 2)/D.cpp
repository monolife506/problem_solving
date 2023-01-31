#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int cnt;
    cin >> cnt;

    int init_cnt = cnt;
    int i = 0;
    bitset<30> ans;
    while (ans.count() != init_cnt)
    {
        int x = (1 << i);
        cout << "- " << x << endl;

        int nxt_cnt;
        cin >> nxt_cnt;

        for (int j = 0; j < nxt_cnt - cnt + 1; ++j)
            ans[i + j] = 0;
        ans[i + nxt_cnt - cnt + 1] = 1;

        i += nxt_cnt - cnt + 2;
        cnt = nxt_cnt;
    }

    cout << "! " << ans.to_ullong() << endl;
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

1100 - 1 = 1011 (2 -> 3)
??.. 100
1011 - 1000 = 11 (3 -> 2)
1100


*/