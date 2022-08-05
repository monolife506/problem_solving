#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

ll cache[300][300];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string S;
    cin >> S;

    for (int i = 0; i + 1 < S.length(); ++i)
    {
        if (S[i] != S[i + 1])
            cache[i][i + 1] = 1;
    }

    for (int d = 2; d < S.length(); ++d)
    {
        for (int i = 0; i + d < S.length(); ++i)
        {
            int j = i + d;
            for (int k = i + 1; k <= j; ++k)
            {
                if (S[i] != S[k])
                {
                    if (k == i + 1)
                        cache[i][j] += cache[k + 1][j];
                    else if (k == j)
                        cache[i][j] += cache[i + 1][k - 1];
                    else
                        cache[i][j] += cache[i + 1][k - 1] * cache[k + 1][j];

                    cache[i][j] %= MOD;
                }
            }
        }
    }

    cout << cache[0][S.length() - 1] << '\n';
}

/*

*/