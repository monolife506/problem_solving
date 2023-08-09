#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int H, W;
    cin >> H >> W;

    vector<vector<char>> ans(H, vector<char>(W));
    for (int i = 0; i < H; ++i)
    {
        string S;
        cin >> S;
        for (int j = 0; j < W; ++j)
            ans[i][j] = S[j];

        for (int j = 0; j < W - 1; ++j)
        {
            if (S[j] == 'T' && S[j + 1] == 'T')
            {
                ans[i][j] = 'P';
                ans[i][j + 1] = 'C';
                j++;
            }
        }
    }

    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
            cout << ans[i][j];
        cout << '\n';
    }
}