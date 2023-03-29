#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct LinearFunc
{
    ll a, b;  // ax + b
    double s; // x >= s
    LinearFunc(ll a = 0, ll b = 0, double s = 0.0)
        : a(a), b(b), s(s) {}

    bool operator<(const LinearFunc &rhs) const
    {
        return s < rhs.s;
    }
};

ll a[100001], b[100001];
ll cache[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    vector<LinearFunc> v;
    v.push_back({b[1], cache[1] = 0});
    for (int i = 2; i <= n; ++i)
    {
        LinearFunc ans =
            *prev(upper_bound(v.begin(), v.end(), LinearFunc(0, 0, a[i])));
        cache[i] = ans.a * a[i] + ans.b;

        if (i == n)
            break;

        LinearFunc f = {b[i], cache[i]};
        while (true)
        {
            LinearFunc g = v.back();
            double cross = (double)(g.b - f.b) / (f.a - g.a);

            if (cross <= g.s)
            {
                v.pop_back();
            }
            else
            {
                f.s = cross;
                v.push_back(f);
                break;
            }
        }
    }

    cout << cache[n] << '\n';
}
/*

Convex Hull Trick (CHT)

cache[1] = 0
cache[i] = min(cache[j] + a[i]b[j]) (1 <= j < i)

*/