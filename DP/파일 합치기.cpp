// 11066번: 파일 합치기

#include <iostream>
#include <array>
using namespace std;
typedef unsigned long long ll;

array<array<ll, 501>, 501> N = {};
array<ll, 501> sum;

int main()
{
    size_t T;
    cin >> T;
    sum[0] = 0;

    ll tmp;
    for (size_t tc = 0; tc < T; tc++)
    {
        int K;
        cin >> K;

        for (size_t i = 1; i <= K; i++)
        {
            cin >> tmp;
            sum[i] = tmp + sum[i - 1];
        }

        for (size_t d = 1; d < K; d++) // 배열의 크기 - 1
        {
            for (size_t i = 1; i + d <= K; i++) // 배열의 시작
            {
                int j = i + d;
                N[i][j] = INT64_MAX;
                for (size_t k = i; k < j; k++)
                {
                    tmp = N[i][k] + N[k + 1][j];
                    if (N[i][j] > tmp)
                        N[i][j] = tmp;
                }
                N[i][j] += sum[j] - sum[i - 1];
            }
        }

        cout << N[1][K] << '\n';
    }
}

/*

40 (30 30 50)
40 (60 50) - 60
40 110 - 60 + 110 = 170
150 - 170 + 150 = 320

(40 30) (30 50)
70 (30 50) - 70
70 80 - 150
150 - 300

(40 30 30) 50
(40 60) 50 - 60
100 50 - 160
150 - 310

*/