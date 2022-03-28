#include <iostream>
using namespace std;
typedef long long ll;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};
const ll MOD = 1000000007;

int tilemap[401][401];
ll cache[201][401][401];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t T;
    int xs, ys, xh, yh;
    cin >> xs >> ys >> T >> xh >> yh;

    size_t N;
    cin >> N;
    for (size_t i = 0; i < N; ++i)
    {
        int xi, yi;
        cin >> xi >> yi;
        if (abs(xs - xi) + abs(ys - yi) <= T)
            tilemap[T - (xs - xi)][T - (ys - yi)] = 1;
    }

    if (abs(xs - xh) + abs(ys - yh) > T)
    {
        cout << 0 << '\n';
    }
    else
    {
        tilemap[T - (xs - xh)][T - (ys - yh)] = 2;
        cache[0][T][T] = 1;
        for (size_t t = 0; t < T; ++t)
        {
            for (size_t x = 0; x <= 2 * T; ++x)
            {
                for (size_t y = 0; y <= 2 * T; ++y)
                {
                    if (tilemap[x][y] == 1)
                        continue;

                    for (size_t i = 0; i < 4; ++i)
                    {
                        int prev_x = x + dx[i];
                        int prev_y = y + dy[i];
                        if (prev_x < 0 || prev_x > 2 * T || prev_y < 0 || prev_y > 2 * T)
                            continue;
                        if (tilemap[prev_x][prev_y] != 0)
                            continue;

                        cache[t + 1][x][y] += cache[t][prev_x][prev_y];
                        cache[t + 1][x][y] %= MOD;
                    }
                }
            }
        }

        ll ans = 0;
        for (size_t t = 0; t <= T; ++t)
        {
            ans += cache[t][T - (xs - xh)][T - (ys - yh)];
            ans %= MOD;
        }

        cout << ans << '\n';
    }
}