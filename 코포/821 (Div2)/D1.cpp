#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        int n, x, y;
        cin >> n >> x >> y;

        string a, b;
        cin >> a >> b;

        vector<int> v;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] != b[i])
                v.push_back(i);
        }

        int diff_cnt = v.size();
        if (diff_cnt % 2 == 1)
        {
            cout << -1 << '\n';
        }
        else if (diff_cnt == 0)
        {
            cout << 0 << '\n';
        }
        else if (diff_cnt == 2)
        {
            if (n == 2)
            {
                cout << x << '\n';
            }
            else if (v[0] + 1 == v[1])
            {
                cout << min(x, y * 2) << '\n';
            }
            else
            {
                cout << y << '\n';
            }
        }
        else
        {
            cout << 1LL * (diff_cnt / 2) * y << '\n';
        }
    }
}