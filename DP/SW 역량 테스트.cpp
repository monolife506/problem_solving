#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

struct Problem
{
    ll M, P, R;
    Problem(ll M = 0, ll P = 0, ll R = 0) : M(M), P(P), R(R) {}
    bool operator<(const Problem &rhs) const
    {
        return rhs.R * P > R * rhs.P;
    }
};

Problem p[50];
ll cache[51][100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, T;
    cin >> N >> T;
    for (int i = 0; i < N; ++i)
        cin >> p[i].M;
    for (int i = 0; i < N; ++i)
        cin >> p[i].P;
    for (int i = 0; i < N; ++i)
        cin >> p[i].R;

    sort(p, p + N);
    for (int i = 0; i < N; ++i)
    {
        for (int t = 0; t <= T; ++t)
        {
            cache[i + 1][t] = max(cache[i + 1][t], cache[i][t]);
            if (t + p[i].R <= T)
            {
                int score = p[i].M - p[i].P * (t + p[i].R);
                if (p[i].M - p[i].P * (t + p[i].R) > 0)
                    cache[i + 1][t + p[i].R] = max(cache[i + 1][t + p[i].R], cache[i][t] + score);
            }
        }
    }

    ll ans = 0;
    for (int t = 0; t <= T; ++t)
        ans = max(ans, cache[N][t]);

    cout << ans << '\n';
}