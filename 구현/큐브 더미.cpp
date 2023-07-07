#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool flag[7][7][7];

int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        flag[x][y][z] = true;
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            for (int k = 1; k <= N; ++k)
            {
                if (!flag[i][j][k])
                    continue;

                bool flag2 = true;
                for (int l = 0; l < 6; ++l)
                {
                    if (!flag[i + dx[l]][j + dy[l]][k + dz[l]])
                    {
                        flag2 = false;
                        break;
                    }
                }

                if (flag2)
                    ans++;
            }
        }
    }

    cout << ans << '\n';
}