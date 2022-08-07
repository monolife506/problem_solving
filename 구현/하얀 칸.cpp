#include <iostream>
using namespace std;

char tilemap[8][8];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ans = 0;
    for (int i = 0; i < 8; ++i)
    {
        cin >> tilemap[i];
        for (int j = 0; j < 8; ++j)
        {
            if (tilemap[i][j] == 'F' && (i + j) % 2 == 0)
                ++ans;
        }
    }

    cout << ans << '\n';
}