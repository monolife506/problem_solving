#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    static int dy[] = {0, 1, 0, -1};
    static int dx[] = {1, 0, -1, 0};

    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n, -1));

    int y = 0, x = 0, d = 0, num[2] = {1, n * n};
    for (int i = 0; i < n * n; ++i)
    {
        if (i % 2 == 0)
            matrix[y][x] = num[0]++;
        else
            matrix[y][x] = num[1]--;

        int nxt_y = y + dy[d];
        int nxt_x = x + dx[d];
        if (nxt_y < 0 || nxt_y >= n || nxt_x < 0 || nxt_x >= n)
        {
            d = (d + 1) % 4;
            nxt_y = y + dy[d];
            nxt_x = x + dx[d];
        }
        else if (matrix[nxt_y][nxt_x] != -1)
        {
            d = (d + 1) % 4;
            nxt_y = y + dy[d];
            nxt_x = x + dx[d];
        }

        y = nxt_y;
        x = nxt_x;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << matrix[i][j] << " ";
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}

/*

n == 2: 2

n == 3: 7

1 9 2
6 5 8
4 7 3

n == 4

 1 16  2 15
11  7 10  3
 6  9  8 14
12  5 13  4

*/