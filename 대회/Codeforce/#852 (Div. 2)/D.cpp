#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int p[200001], q[200001];
int idx_p[200001], idx_q[200001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i];
        idx_p[p[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> q[i];
        idx_q[q[i]] = i;
    }

    ll ans = 0;

    int l_idx = idx_p[1], r_idx = idx_q[1];
    if (l_idx > r_idx)
        swap(l_idx, r_idx);

    ans += 1LL * (l_idx - 1) * l_idx / 2;
    ans += 1LL * (r_idx - l_idx - 1) * (r_idx - l_idx) / 2;
    ans += 1LL * (n - r_idx) * (n - r_idx + 1) / 2;

    int pl = idx_p[1], pr = idx_p[1], ql = idx_q[1], qr = idx_q[1];
    for (int i = 2; i <= n; ++i) // mex
    {
        pl = min(pl, idx_p[i - 1]);
        pr = max(pr, idx_p[i - 1]);
        ql = min(ql, idx_q[i - 1]);
        qr = max(qr, idx_q[i - 1]);

        if (idx_p[i] >= min(pl, ql) && idx_p[i] <= max(pr, qr))
            continue;
        if (idx_q[i] >= min(pl, ql) && idx_q[i] <= max(pr, qr))
            continue;

        int l = 1;
        int r = n;

        if (idx_p[i] < pl)
            l = max(l, idx_p[i] + 1);
        else
            r = min(r, idx_p[i] - 1);

        if (idx_q[i] < ql)
            l = max(l, idx_q[i] + 1);
        else
            r = min(r, idx_q[i] - 1);

        ans += 1LL * (r - max(pr, qr) + 1) * (min(pl, ql) - l + 1);
    }

    cout << ++ans << '\n';
}

/*

min(pl, ql) ~ max(pr, qr)

*/