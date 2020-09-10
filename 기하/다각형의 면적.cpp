// 2166번: 다각형의 면적

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

P p[10000];

double ccw(const P &A, const P &B, const P &C)
{
    double cross = (B.first - A.first) * (C.second - A.second);
    cross -= (B.second - A.second) * (C.first - A.first);
    return cross / 2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    for (size_t i = 0; i < N; i++)
        cin >> p[i].first >> p[i].second;

    double ans = 0;
    for (size_t i = 1; i < N - 1; i++)
        ans += ccw(p[0], p[i], p[i + 1]);

    cout << fixed << setprecision(1) << abs(ans);
}