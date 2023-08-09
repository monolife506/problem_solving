#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll dp[3][1 << 3][200000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    string S;
    cin >> S;

    if (S[0] == 'M')
        dp[0][1 << A[0]][0] = 1;

    for (int k = 1; k < N; ++k)
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < (1 << 3); ++j)
                dp[i][j][k] = dp[i][j][k - 1];
        }

        if (S[k] == 'M')
        {
            dp[0][1 << A[k]][k]++;
        }
        else if (S[k] == 'E')
        {
            for (int j = 0; j < (1 << 3); ++j)
            {
                if (__builtin_popcount(j) == 1)
                    dp[1][j | (1 << A[k])][k] += dp[0][j][k - 1];
            }
        }
        else if (S[k] == 'X')
        {
            for (int j = 0; j < (1 << 3); ++j)
            {
                if (__builtin_popcount(j) != 0 && __builtin_popcount(j) != 3)
                    dp[2][j | (1 << A[k])][k] += dp[1][j][k - 1];
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < (1 << 3); ++i)
    {
        if ((i & 1) == 0)
            continue;
        else if ((i & 2) == 0)
            ans += dp[2][i][N - 1];
        else if ((i & 4) == 0)
            ans += dp[2][i][N - 1] * 2;
        else
            ans += dp[2][i][N - 1] * 3;
    }

    cout << ans << '\n';
}

/*

M

E

X

*/