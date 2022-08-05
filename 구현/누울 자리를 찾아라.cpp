#include <iostream>
using namespace std;

char tilemap[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> tilemap[i];

    int ans[2] = {};
    for (int i = 0; i < N; ++i)
    {
        int cnt = 0;
        for (int j = 0; j < N; ++j)
        {
            if (tilemap[i][j] == '.')
            {
                ++cnt;
            }
            else
            {
                if (cnt >= 2)
                    ans[0]++;
                cnt = 0;
            }
        }

        if (cnt >= 2)
        {
            ans[0]++;
            cnt = 0;
        }
    }
    for (int j = 0; j < N; ++j)
    {
        int cnt = 0;
        for (int i = 0; i < N; ++i)
        {
            if (tilemap[i][j] == '.')
            {
                ++cnt;
            }
            else
            {
                if (cnt >= 2)
                    ans[1]++;
                cnt = 0;
            }
        }

        if (cnt >= 2)
        {
            ans[1]++;
            cnt = 0;
        }
    }

    cout << ans[0] << " " << ans[1] << '\n';
}