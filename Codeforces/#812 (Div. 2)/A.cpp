#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 0; tc < T; ++tc)
    {
        int n;
        cin >> n;

        int max_num[4] = {};
        for (int i = 0; i < n; ++i)
        {
            int x, y;
            cin >> x >> y;

            if (x < 0)
                max_num[0] = max(max_num[0], -x);
            else if (x > 0)
                max_num[1] = max(max_num[1], x);
            else if (y < 0)
                max_num[2] = max(max_num[2], -y);
            else
                max_num[3] = max(max_num[3], y);
        }

        int ans = 0;
        for (int i = 0; i < 4; ++i)
            ans += max_num[i] * 2;

        cout << ans << '\n';
    }
}