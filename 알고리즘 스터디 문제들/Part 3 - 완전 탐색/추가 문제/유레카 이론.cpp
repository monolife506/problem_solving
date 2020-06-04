#include <iostream>
#include <array>
using namespace std;

array<int, 1001> N; // 삼각수의 값

int main()
{
    N[0] = 0;
    for (size_t i = 1; i <= 45; i++) // 1 ~ 45까지의 합부터 처음으로 1000을 넘김
    {
        N[i] = i + N[i - 1];
        // i번째 삼각수는 1부터 i까지의 합이니,
        // N[i] = N[i - 1] + i라는 점화 관계가 성립한다.
    }

    size_t T;
    cin >> T;

    int K;
    bool flag = false; // K가 3개의 삼각수의 합으로 표현되는지 확인
    for (size_t tc = 0; tc < T; tc++)
    {
        flag = false;
        cin >> K;

        for (size_t i = 1; i <= 45; i++)
        {
            for (size_t j = 1; j <= 45; j++)
            {
                for (size_t k = 1; k <= 45; k++)
                {
                    if (K == N[i] + N[j] + N[k])
                        flag = true;
                }
            }
        }

        cout << flag << '\n';
    }
}