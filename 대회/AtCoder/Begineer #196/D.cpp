#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int H, W, A, B;
    cin >> H >> W >> A >> B;

    vector<vector<vector<ll>>> dp(A + 1, vector<vector<ll>>(H * W + 1, vector<ll>(1 << W, 0)));
    dp[A][0][0] = 1;
    for (int h = 0; h < H; ++h)
    {
        for (int w = 0; w < W; ++w)
        {
            int cur = h * W + w;
            for (int a = A; a >= 0; --a)
            {
                for (int i = 0; i < (1 << W); ++i)
                {
                    dp[a][cur + 1][i >> 1] += dp[a][cur][i];
                    if (a != 0 && !(i & 1))
                    {
                        if (h != H - 1)
                            dp[a - 1][cur + 1][(i >> 1) | (1 << (W - 1))] += dp[a][cur][i];
                        if (w != W - 1 && ((i & 2) == 0))
                            dp[a - 1][cur + 2][i >> 2] += dp[a][cur][i];
                    }
                }
            }
        }
    }

    cout << dp[0][H * W][0] << '\n';
}

/*


*/