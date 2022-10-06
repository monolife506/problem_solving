#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll w, h, L;
    cin >> w >> h >> L;

    ll ans = L * 2;
    for (ll x = 1; x < L; ++x)
        ans += (ll)sqrt(L * L - x * x) * 3;

    if (L > h)
    {
        ans += L - h;
        for (ll x = 1; x < min(L - h, w + 1); ++x)
            ans += (ll)sqrt((L - h) * (L - h) - x * x);
    }
    if (L > w)
    {
        ans += L - w;
        for (ll y = 1; y < min(L - w, h + 1); ++y)
            ans += (ll)sqrt((L - w) * (L - w) - y * y);
    }
    if (L > w + h)
    {
        for (ll x = w + 1; x < L - h; ++x)
            ans += (ll)sqrt((L - h) * (L - h) - x * x);

        for (ll y = h + 1; y < L - w; ++y)
        {
            double min_x = sqrt((L - h) * (L - h) - (y - h) * (y - h));
            double max_x = sqrt((L - w) * (L - w) - y * y) + w;
            ans += max(0LL, (ll)max_x - (ll)min_x);
        }
    }

    cout << ans << '\n';
}

/*

x^2 + y^2 <= L

y^2 <= L - x^2
y <= sqrt()

min_x < x <= max_x인 격자점의 개수

2 5
2.5 5
2.7 4.4

4 - 2

3 4 5

*/