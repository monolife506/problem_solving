#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    ll k;
    cin >> k;

    ll max_num = -1;
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i] > a[i + 1])
            max_num = max(a[i], max_num);
    }

    ll ans = 0;
    if (max_num != -1)
    {
        ll p_cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (max_num > a[i])
            {
                p_cnt += max_num - a[i];
                a[i] = max_num;
            }
        }

        if (k >= p_cnt)
        {
            ans++;
            k -= p_cnt;
        }
        else
        {
            cout << 0 << '\n';
            return 0;
        }
    }

    int n_cnt = 1;
    while (n_cnt != n)
    {
        for (int i = n_cnt; i < n; ++i)
        {
            if (a[i - 1] == a[i])
                n_cnt++;
            else
                break;
        }

        if (n_cnt == n)
            break;

        ll p_cnt = (a[n_cnt] - a[n_cnt - 1]) * n_cnt;
        if (k >= p_cnt)
        {
            ans += p_cnt / n_cnt;
            k -= p_cnt;
            n_cnt++;
        }
        else
        {
            ans += k / n_cnt;
            cout << ans << '\n';
            return 0;
        }
    }

    ans += k / n;
    cout << ans << '\n';
}

/*

a1 a2 ... an

an == max?

3 2 7 5 9

*/