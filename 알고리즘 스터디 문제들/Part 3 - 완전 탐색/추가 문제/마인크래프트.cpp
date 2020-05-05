#include <iostream>
#include <array>
using namespace std;

// 높이 i인 땅의 개수 H[i]
array<int, 256 + 1> H = {};

int main()
{
    int N, M, B;
    cin >> N >> M >> B;

    int tmp;
    int maxH = 0;
    int minH = 256;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            cin >> tmp;
            H[tmp]++;

            if (maxH < tmp)
                maxH = tmp;
            if (minH > tmp)
                minH = tmp;
        }
    }

    int min_time = INT32_MAX;
    int aCnt, rCnt;
    int targetH;

    for (int h = minH; h <= maxH; h++)
    {
        aCnt = 0;
        rCnt = 0;
        for (size_t i = minH; i <= maxH; i++)
        {
            if (h > i)
                aCnt += (h - i) * H[i];
            else
                rCnt += (i - h) * H[i];
        }

        tmp = aCnt + 2 * rCnt;
        if (B + rCnt >= aCnt && min_time >= tmp)
        {
            min_time = tmp;
            targetH = h;
        }
    }

    cout << min_time << " " << targetH;
}