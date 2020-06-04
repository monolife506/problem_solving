#include <iostream>
#include <array>
using namespace std;

array<int, 301> st; // st[i] = i번째 계단의 수

// 타뷸레이션을 위한 array
array<array<int, 2>, 301> ta;
// ta[i][1] == 다음 계단을 밟을 수 있는 경우의 i번째 계단에서 최대 합
// ta[i][0] == 다음 계단을 밟을 수 없는 경우 i번째 계단에서 최대 합

int main()
{
    size_t N;
    cin >> N;

    st[0] = 0;
    for (size_t i = 1; i <= N; i++)
        cin >> st[i];

    ta[0][0] = ta[0][1] = ta[1][0] = 0;
    ta[1][1] = st[1];
    for (size_t i = 2; i <= N; i++)
    {
        ta[i][0] = ta[i - 1][1] + st[i];
        ta[i][1] = max(ta[i - 2][0], ta[i - 2][1]) + st[i];
    }
    cout << max(ta[N][0], ta[N][1]);
}