#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, L, K;
    cin >> N >> M >> L >> K;

    vector<pii> p(K);
    for (int i = 0; i < K; ++i)
        cin >> p[i].first >> p[i].second;

    int ans = K - 1;
    for (int i = 0; i < K; ++i)
    {
        for (int j = 0; j < K; ++j)
        {
            int xl = p[i].first;
            int xr = xl + L;
            int yl = p[j].second;
            int yr = yl + L;

            int cnt = 0;
            for (int k = 0; k < K; ++k)
            {
                int &x = p[k].first;
                int &y = p[k].second;
                if (xl <= x && x <= xr && yl <= y && y <= yr)
                    cnt++;
            }

            ans = min(ans, K - cnt);
        }
    }

    cout << ans << '\n';
}