#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int ccw(pii p, pii a, pii b)
{
    ll cross = 1LL * (a.first - p.first) * (b.second - p.second) - 1LL * (b.first - p.first) * (a.second - p.second);
    return (cross > 0) - (cross < 0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<pii> p(N);
    for (int i = 0; i < N; ++i)
        cin >> p[i].first >> p[i].second;

    ll ans = 0;
    for (int i = 0; i < N - 2; ++i)
    {
        for (int j = i + 1; j < N - 1; ++j)
        {
            for (int k = j + 1; k < N; ++k)
            {
                if (ccw(p[i], p[j], p[k]) != 0)
                    ans++;
            }
        }
    }

    cout << ans << '\n';
}

/*

(p[i].y - p[j].y) / (p[i].x - p[j].x)
(p[j].y - p[k].y) / (p[j].x - p[k].x)

*/