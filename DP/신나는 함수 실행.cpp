#include <cstring>
#include <iostream>
using namespace std;

int dp[101][101][101];

int w(int a, int b, int c)
{
    if (dp[a][b][c] != -1)
        return dp[a][b][c];

    if (a <= 50 || b <= 50 || c <= 50)
        dp[a][b][c] = 1;
    else if (a > 70 || b > 70 || c > 70)
        dp[a][b][c] = w(70, 70, 70);
    else if (a < b && b < c)
        dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else
        dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);

    return dp[a][b][c];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp, -1, sizeof(dp));

    while (true) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1)
            break;

        cout << "w(" << a << ", " << b << ", " << c << ") = ";

        a += 50;
        b += 50;
        c += 50;

        cout << w(a, b, c) << '\n';
    }
}