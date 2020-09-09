// 17386번: 선분 교차

#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

P p[4];

int ccw(int i, int j, int k)
{
    ll cross = (p[j].first - p[i].first) * (p[k].second - p[i].second);
    cross -= (p[j].second - p[i].second) * (p[k].first - p[i].first);
    return (cross > 0) - (cross < 0);
}

int main()
{
    for (size_t i = 0; i < 4; i++)
        cin >> p[i].first >> p[i].second;

    bool flag1 = (ccw(0, 1, 2) * ccw(0, 1, 3) == -1);
    bool flag2 = (ccw(2, 3, 0) * ccw(2, 3, 1) == -1);
    cout << (flag1 && flag2);
}