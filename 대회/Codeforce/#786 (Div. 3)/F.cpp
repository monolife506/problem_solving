#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

char desktop[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> desktop[i];
        for (int j = 0; j < m; ++j)
        {
            if (desktop[i][j] == '*')
                cnt++;
        }
    }

    int inner_cnt = 0, external_cnt = 0;
    for (int j = 0; j < m; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            if (desktop[i][j] == '*')
            {
                if (n * j + (i + 1) <= cnt)
                    inner_cnt++;
                else
                    external_cnt++;
            }
        }
    }

    for (int i = 0; i < q; ++i)
    {
        int x, y;
        cin >> x >> y;

        if (desktop[x - 1][y - 1] == '.')
        {
            if (desktop[cnt % n][cnt / n] == '*')
            {
                inner_cnt++;
                external_cnt--;
            }

            cnt++;
            if (n * (y - 1) + x <= cnt)
                inner_cnt++;
            else
                external_cnt++;

            desktop[x - 1][y - 1] = '*';
        }
        else
        {
            if (desktop[(cnt - 1) % n][(cnt - 1) / n] == '*')
            {
                inner_cnt--;
                external_cnt++;
            }

            cnt--;
            if (n * (y - 1) + x <= cnt)
                inner_cnt--;
            else
                external_cnt--;

            desktop[x - 1][y - 1] = '.';
        }

        cout << external_cnt << '\n';
    }
}

/*

*.**
.*..
**..
.*.*



*/