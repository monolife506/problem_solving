#include <iostream>
using namespace std;

int x[500000], y[500000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N;
    cin >> N;
    for (size_t i = 0; i < N; ++i)
        cin >> x[i] >> y[i];

    int sx, sy;
    cin >> sx >> sy;
    for (size_t i = 0; i < N; ++i)
    {
        x[i] -= sx;
        y[i] -= sy;
    }

    int flag = 4;

    // 동쪽
    for (size_t i = 0; i < N; ++i)
    {
        if (x[i] < 0)
            continue;
        if (-x[i] <= y[i] && y[i] <= x[i])
        {
            --flag;
            break;
        }
    }

    // 서쪽
    for (size_t i = 0; i < N; ++i)
    {
        if (x[i] > 0)
            continue;
        if (x[i] <= y[i] && y[i] <= -x[i])
        {
            --flag;
            break;
        }
    }

    // 남쪽
    for (size_t i = 0; i < N; ++i)
    {
        if (y[i] > 0)
            continue;
        if (y[i] <= x[i] && x[i] <= -y[i])
        {
            --flag;
            break;
        }
    }

    // 북쪽
    for (size_t i = 0; i < N; ++i)
    {
        if (y[i] < 0)
            continue;
        if (-y[i] <= x[i] && x[i] <= y[i])
        {
            --flag;
            break;
        }
    }

    cout << (flag ? "YES" : "NO") << '\n';
}