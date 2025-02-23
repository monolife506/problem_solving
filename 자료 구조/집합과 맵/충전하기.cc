#include <bits/stdc++.h>
#define endl '\n'
// #define FILE_RW
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void solve()
{
    int n, q;
    cin >> n >> q;

    set<int> s;
    vector<int> order(n + 1, -1);
    for (int i = 1; i <= n; ++i)
        s.insert(i);

    for (int qi = 1; qi <= q; ++qi)
    {
        int t, i;
        cin >> t >> i;

        if (t == 1)
        {
            set<int>::iterator lb = s.lower_bound(i);
            if (lb == s.end())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << *lb << endl;
                s.erase(lb);
                order[*lb] = qi;
            }
        }
        else
        {
            if (order[i] == -1)
            {
                cout << -1 << endl;
                continue;
            }

            cout << order[i] << endl;
            s.insert(i);

            order[i] = -1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef FILE_RW
    freopen("local.in", "r", stdin);
    freopen("local.out", "w", stdout);
#endif

    solve();
}

/*

10^9

50% 낵
50%

log2(10^9)


*/