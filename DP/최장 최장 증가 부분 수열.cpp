#include <iostream>
using namespace std;

int num[100][100], cache[100][100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> num[i][j];
            cache[i][j] = 1;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int y = 0; y <= i; ++y)
            {
                for (int x = 0; x <= j; ++x)
                {
                    if (num[i][j] > num[y][x])
                        cache[i][j] = max(cache[i][j], cache[y][x] + 1);
                }
            }
        }
    }

    int ans = 1;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            ans = max(ans, cache[i][j]);
    }

    cout << ans << '\n';
}

/*

3
2 3 1
1 1 1
1 1 5

*/