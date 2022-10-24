#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll psum[200002];

void solve()
{
    int n;
    cin >> n;

    vector<int> idx(n), l(n), r(n);
    for (int i = 0; i < n; ++i)
    {
        int p;
        cin >> p;
        idx[p] = i;
    }

    l[0] = idx[0];
    r[0] = idx[0];
    for (int i = 1; i < n; ++i)
    {
        l[i] = min(l[i - 1], idx[i]);
        r[i] = max(r[i - 1], idx[i]);
    }

    ll ans = 1;
    for (int m = 1; m < n; ++m)
    {
        if (l[m - 1] < idx[m] && r[m - 1] > idx[m])
            continue;

        int sz = r[m - 1] - l[m - 1] + 1;
        int re = m * 2 - sz;
        int p, q;

        if (idx[m] < l[m - 1])
        {
            p = l[m - 1] - idx[m] - 1;
            q = (n - 1) - r[m - 1];
        }
        else // (idx[m] > r[m - 1])
        {
            p = l[m - 1];
            q = (idx[m] - 1) - r[m - 1];
        }

        if (re < 0)
            continue;
        if (p > q)
            swap(p, q);

        ll tmp = 0;
        if (p >= re && q >= re)
            tmp += psum[re + 1];
        else if (q >= re)
            tmp += psum[re + 1] - psum[re - p];
        else // q < r
        {
            tmp += 1LL * (min(p, re - q) + 1) * (q + 1);
            if (re - q < p)
            {
                tmp += 1LL * (p - (re - q)) * (re + 1);
                tmp -= psum[p] - psum[re - q];
            }
        }

        ans += tmp;
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 1; i <= 200001; ++i)
        psum[i] = psum[i - 1] + i;

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solve();
}

/*

3 1 0 2 4

1: 2
2: 2
3: 2
4: 2

m == m
m의 index는 i
오른쪽이나 왼쪽에 0 ... m - 1까지 모두 존재
존재하는 index가 왼쪽이나 오른쪽으로 j번째

1 2 3 4 5

p 4
q 3

0 0 ~ r
1 0 ~ r - 1
2 0 ~ r - 2
...
r 0

p >= r && q >= r: sum(1 ~ r + 1)

0 0 ~ r
1 0 ~ r - 1
2 0 ~ r - 2
...
p 0 ~ r - p

p < r && q >= r: sum(r - p + 1 ~ r + 1)

4
2 3

0 0 ~ 3
1 0 ~ 3
2 0 ~ 2

0 <= x <= min(p, r - q) -> (q + 1)
r - q < x <= p -> (r - x + 1)

+ (r + 1) * (p - (r - q))
- sum(r - q + 1 ~ p)

*/