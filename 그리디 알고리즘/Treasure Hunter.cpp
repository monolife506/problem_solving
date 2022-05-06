#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

struct Treasure
{
    int y, x;
    Treasure(int y = 0, int x = 0) : y(y), x(x) {}

    bool operator<(const Treasure &rhs) const
    {
        return (y != rhs.y) ? y < rhs.y : x < rhs.x;
    }
};

Treasure t[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t m, n, k;
    int ans = 0;
    set<int> s;

    cin >> m >> n >> k;
    for (size_t i = 0; i < k; ++i)
    {
        int y, x;
        cin >> y >> x;
        t[i].y = y;
        t[i].x = x;
    }

    sort(t, t + k);
    s.insert(0);
    for (size_t i = 0; i < k; ++i)
    {
        auto it = s.upper_bound(t[i].x);
        --it;
        if (*it == 0)
        {
            ++ans;
            s.insert(t[i].x);
        }
        else
        {
            s.erase(it);
            s.insert(t[i].x);
        }
    }

    cout << ans << '\n';
}