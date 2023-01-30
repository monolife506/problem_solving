#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> factors[100001];

void precompute()
{
    for (int i = 1; i <= 100'000; ++i)
    {
        for (int j = i; j <= 100'000; j += i)
            factors[j].push_back(i);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a.begin(), a.end());

    int l = 0, r = 0, cnt = 0, ans = INT32_MAX;
    vector<int> m_cnt(m + 1, 0);
    while (l < n)
    {
        if (r < n && cnt < m)
        {
            for (int f : factors[a[r]])
            {
                if (f > m)
                    continue;
                if (m_cnt[f] == 0)
                    cnt++;
                m_cnt[f]++;
            }

            r++;
        }
        else
        {
            for (int f : factors[a[l]])
            {
                if (f > m)
                    continue;
                if (m_cnt[f] == 1)
                    cnt--;
                m_cnt[f]--;
            }

            l++;
        }

        if (cnt == m)
            ans = min(ans, a[r - 1] - a[l]);
    }

    cout << (ans != INT32_MAX ? ans : -1) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    precompute();

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}

/*

m = 7
4 5 6 7 30

*/