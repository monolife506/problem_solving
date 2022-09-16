#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
    {
        int n;
        cin >> n;

        vector<int> x(n), y(n), diff(n);
        for (int i = 0; i < n; ++i)
            cin >> x[i];
        for (int i = 0; i < n; ++i)
            cin >> y[i];
        for (int i = 0; i < n; ++i)
            diff[i] = y[i] - x[i];

        sort(diff.begin(), diff.end());

        int ans = 0, l = 0, r = n - 1;
        while (l < r)
        {
            if (diff[l] + diff[r] >= 0)
            {
                ++ans;
                ++l;
                --r;
            }
            else
            {
                ++l;
            }
        }

        cout << ans << '\n';
    }
}

/*

-3 0 -8 2 1 5

-8 -3 0 1 2 5


-1 -1 0 0 2 2 -> 3
-1 0 3 -> 1

*/