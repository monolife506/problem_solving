#include <bits/stdc++.h>
using namespace std;

int psum[301][301];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> psum[i][j];
            psum[i][j] += psum[i - 1][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = i; j <= m; ++j)
        {
            int l = 1, r = 1, sum = 0;
            while (true)
            {
                if (sum >= 10)
                {
                    sum -= psum[j][l] - psum[i - 1][l];
                    ++l;
                }
                else if (r > n)
                {
                    break;
                }
                else
                {
                    sum += psum[j][r] - psum[i - 1][r];
                    ++r;
                }

                if (sum == 10)
                    ++ans;
            }
        }
    }

    cout << ans << '\n';
}