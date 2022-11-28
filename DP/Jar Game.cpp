#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 987654321;
int cache[101][101][101][101];

int dp(int a, int b, int c, int k)
{
    int &ret = cache[a][b][c][k];
    if (ret != INF)
        return ret;
    if (a == 0 && b == 0 && c == 0)
        return ret = 0;

    if (k % 2 == 1) // F
    {
        ret = -INF;

        if (a != 0)
            ret = max(ret, dp(max(0, a - k), b, c, k + 1) + min(a, k));
        if (b != 0)
            ret = max(ret, dp(a, max(0, b - k), c, k + 1) + min(b, k));
        if (c != 0)
            ret = max(ret, dp(a, b, max(0, c - k), k + 1) + min(c, k));
    }
    else // S
    {
        ret = INF;

        if (a != 0)
            ret = min(ret, dp(max(0, a - k), b, c, k + 1) - min(a, k));
        if (b != 0)
            ret = min(ret, dp(a, max(0, b - k), c, k + 1) - min(b, k));
        if (c != 0)
            ret = min(ret, dp(a, b, max(0, c - k), k + 1) - min(c, k));
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill_n(&cache[0][0][0][0], 101 * 101 * 101 * 101, INF);

    int a, b, c;
    cin >> a >> b >> c;

    int ans = dp(a, b, c, 1);
    if (ans > 0)
        cout << "F" << '\n';
    else if (ans == 0)
        cout << "D" << '\n';
    else
        cout << "S" << '\n';
}