#include <iostream>
using namespace std;

void solve()
{
    static int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    static int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    int n, m;
    cin >> n >> m;
    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < m; ++x)
        {
            bool isolated = true;
            for (int i = 0; i < 8; ++i)
            {
                int nxt_y = y + dy[i];
                int nxt_x = x + dx[i];
                if (nxt_y < 0 || nxt_y >= n || nxt_x < 0 || nxt_x >= m)
                    continue;
                else
                    isolated = false;
            }

            if (isolated)
            {
                cout << y + 1 << " " << x + 1 << '\n';
                return;
            }
        }
    }

    cout << 1 << " " << 1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solve();
}