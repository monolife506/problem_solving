#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(k);
    for (int i = 0; i < k; ++i)
        cin >> a[i];

    int nxt_card = k;
    priority_queue<int> pq;
    for (int i = 0; i < k; ++i)
    {
        pq.push(a[i]);
        if (pq.size() == n * m - 2)
        {
            cout << "TIDAK" << '\n';
            return;
        }
        while (!pq.empty() && pq.top() == nxt_card)
        {
            --nxt_card;
            pq.pop();
        }
    }

    cout << "YA" << '\n';
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

X . .
. . .
. . X

*/