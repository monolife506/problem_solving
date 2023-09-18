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

    int H, W, N;
    cin >> H >> W >> N;

    vector<tuple<int, int, pii>> p;
    for (int i = 0; i < N; ++i)
    {
        int r, c, a;
        cin >> r >> c >> a;
        p.push_back({a, i, {r, c}});
    }

    sort(p.begin(), p.end(), greater<tuple<int, int, pii>>());
    vector<int> dp(N, -1), max_r(H + 1, -1), max_c(W + 1, -1);
    queue<pii> tmp_r, tmp_c;
    for (int i = 0; i < N; ++i)
    {
        int a = get<0>(p[i]);
        int idx = get<1>(p[i]);
        int r = get<2>(p[i]).first;
        int c = get<2>(p[i]).second;

        dp[idx] = max(max_r[r], max_c[c]) + 1;
        tmp_r.push({r, dp[idx]});
        tmp_c.push({c, dp[idx]});

        if (i == N - 1 || a != get<0>(p[i + 1]))
        {
            while (!tmp_r.empty())
            {
                pii cur = tmp_r.front();
                tmp_r.pop();
                max_r[cur.first] = max(max_r[cur.first], cur.second);
            }
            while (!tmp_c.empty())
            {
                pii cur = tmp_c.front();
                tmp_c.pop();
                max_c[cur.first] = max(max_c[cur.first], cur.second);
            }
        }
    }

    for (int i = 0; i < N; ++i)
        cout << dp[i] << '\n';
}