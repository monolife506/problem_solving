#include <iostream>
#include <array>
using namespace std;

// 색종이의 상태를 나타내는 배열
array<array<bool, 100>, 100> P = {};

// P[i][j] = (i, j)와 (i + 1, j + 1)을 양 점으로 하는
// 도화지 위 정사각형 구역이 검은 영역인지 확인하는 변수

int main()
{
    size_t N;
    cin >> N;

    int X, Y;
    for (size_t i = 0; i < N; i++)
    {
        cin >> X >> Y;
        for (size_t j = X; j < X + 10; j++)
        {
            for (size_t k = Y; k < Y + 10; k++)
                P[j][k] = true;
        }
    }

    int ans = 0;
    for (size_t i = 0; i < 100; i++)
    {
        for (size_t j = 0; j < 100; j++)
        {
            if (P[i][j])
                ans++;
        }
    }
    cout << ans;
}