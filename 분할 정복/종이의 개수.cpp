// 1780번: 종이의 개수

#include <iostream>
#include <array>
using namespace std;

array<int, 3> cnt = {};
array<array<int, 2187>, 2187> map;

void ans(int N, int X, int Y)
{
    for (size_t i = X; i < X + N; i++)
    {
        for (size_t j = Y; j < Y + N; j++)
        {
            if (map[X][Y] != map[i][j])
            {
                ans(N / 3, X, Y);
                ans(N / 3, X + (N / 3), Y);
                ans(N / 3, X + (2 * N / 3), Y);
                ans(N / 3, X, Y + (N / 3));
                ans(N / 3, X + (N / 3), Y + (N / 3));
                ans(N / 3, X + (2 * N / 3), Y + (N / 3));
                ans(N / 3, X, Y + (2 * N / 3));
                ans(N / 3, X + (N / 3), Y + (2 * N / 3));
                ans(N / 3, X + (2 * N / 3), Y + (2 * N / 3));
                return;
            }
        }
    }
    ++cnt[map[X][Y] + 1];
}

int main()
{
    size_t N;
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
            cin >> map[i][j];
    }

    ans(N, 0, 0);
    for (size_t i = 0; i < 3; i++)
        cout << cnt[i] << '\n';
}