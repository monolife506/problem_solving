#include <iostream>
using namespace std;

char from[10001], to[10001], move_coin[2];
bool cache[3][10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, a, b;
    cin >> n >> from >> to >> a >> b;

    int shift_cnt = 0;
    for (int i = 0; i <= n; ++i)
    {
        if (i == a || i == b)
        {
            move_coin[shift_cnt++] = from[i];
            continue;
        }

        from[i - shift_cnt] = from[i];
    }

    cache[0][0] = true;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (from[j - i] == to[j] && cache[i][j])
                cache[i][j + 1] = true;
            if (move_coin[i] == to[j] && cache[i][j])
                cache[i + 1][j + 1] = true;
        }
    }

    cout << (cache[2][n] ? "YES" : "NO") << '\n';
}