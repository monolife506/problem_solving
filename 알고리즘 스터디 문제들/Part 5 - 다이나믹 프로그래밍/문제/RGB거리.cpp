#include <iostream>
#include <array>
using namespace std;

// j에 대해 R = 0, G = 1, B = 2
// val[i][j] = i번째 집을 j색으로 칠하는데 드는 비용
array<array<int, 3>, 1001> val;
// sum[i][j] = i번째 집까지 색을 칠하고 i번째 집의 색이 j일 때
// 지금까지 칠한 비용의 합의 최솟값
array<array<int, 3>, 1001> sum;

int main()
{
    size_t N;
    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 0; j < 3; j++)
            cin >> val[i][j];
    }

    sum[0].fill(0);
    for (size_t i = 1; i <= N; i++)
    {
        sum[i][0] = min(sum[i - 1][1], sum[i - 1][2]) + val[i][0];
        sum[i][1] = min(sum[i - 1][0], sum[i - 1][2]) + val[i][1];
        sum[i][2] = min(sum[i - 1][0], sum[i - 1][1]) + val[i][2];
    }
    cout << min(sum[N][0], min(sum[N][1], sum[N][2]));
}