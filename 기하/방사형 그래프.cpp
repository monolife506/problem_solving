#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef pair<double, double> pdd;

const double sqrt2 = sqrt(2);
const double x[8] = {0, sqrt2, 2, sqrt2, 0, -sqrt2, -2, -sqrt2};
const double y[8] = {2, sqrt2, 0, -sqrt2, -2, -sqrt2, 0, sqrt2};

int a[8], ans;

int ccw(pdd p, pdd a, pdd b)
{
    double cross = (a.first - p.first) * (b.second - p.second) - (b.first - p.first) * (a.second - p.second);
    return (cross > 0) - (cross < 0);
}

void backtracking(int cnt, int mask)
{
    static vector<pdd> v;

    if (cnt == 8)
    {
        bool flag = true;
        for (int i = 0; i < 8; ++i)
        {
            if (ccw(v[i], v[(i + 1) % 8], v[(i + 2) % 8]) == 1)
                flag = false;
        }

        ans += flag;
    }

    for (int i = 0; i < 8; ++i)
    {
        if ((mask & (1 << i)) != 0)
            continue;

        v.push_back({a[i] * x[cnt], a[i] * y[cnt]});
        backtracking(cnt + 1, (mask | (1 << i)));
        v.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 8; ++i)
        cin >> a[i];

    backtracking(0, 0);

    cout << ans << '\n';
}