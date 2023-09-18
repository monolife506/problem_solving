#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll A[51][51];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int H, W;
    cin >> H >> W;
    for (int i = 1; i <= H; ++i)
    {
        for (int j = 1; j <= W; ++j)
            cin >> A[i][j];
    }

    bool flag = true;
    for (int i1 = 1; i1 < H; ++i1)
    {
        for (int j1 = 1; j1 < W; ++j1)
        {
            for (int i2 = i1 + 1; i2 <= H; ++i2)
            {
                for (int j2 = j1 + 1; j2 <= W; ++j2)
                {
                    if (A[i1][j1] + A[i2][j2] > A[i2][j1] + A[i1][j2])
                        flag = false;
                }
            }
        }
    }

    cout << (flag ? "Yes" : "No") << '\n';
}