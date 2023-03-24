#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<vector<ll>> psum(1001, vector<ll>(1001, 0));
    for (int i = 0; i < n; ++i)
    {
        int h, w;
        cin >> h >> w;
        psum[h][w] += h * w;
    }
    for (int i = 1; i <= 1000; ++i)
    {
        for (int j = 1; j <= 1000; ++j)
            psum[i][j] += psum[i][j - 1];
    }
    for (int i = 1; i <= 1000; ++i)
    {
        for (int j = 1; j <= 1000; ++j)
            psum[i][j] += psum[i - 1][j];
    }

    for (int i = 0; i < q; ++i)
    {
        int hs, ws, hb, wb;
        cin >> hs >> ws >> hb >> wb;
        cout << psum[hb - 1][wb - 1] - (psum[hb - 1][ws] + psum[hs][wb - 1]) + psum[hs][ws] << '\n';
    }
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