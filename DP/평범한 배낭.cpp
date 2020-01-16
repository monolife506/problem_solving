// 12865번: 평범한 배낭

#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

struct DP
{
    int value{};
    array<bool, 100> used{};
};
array<array<int, 2>, 100> S;
array<DP, 100'000 + 1> W;

int main()
{
    int N, K;
    cin >> N >> K;
    for (size_t i = 0; i < N; i++)
    {
        cin >> S[i][0] >> S[i][1];
    }

    int max_value{};
    for (size_t i = 1; i <= K; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            if (S[j][0] <= i && W[i - S[j][0]].value + S[j][1] > W[i].value)
            {
                if (!W[i - S[j][0]].used[j])
                {
                    W[i].value = W[i - S[j][0]].value + S[j][1];
                    W[i].used = W[i - S[j][0]].used;
                    W[i].used[j] = true;

                    if (W[i].value > max_value)
                    {
                        max_value = W[i].value;
                    }
                }
            }
        }
    }

    cout << max_value;
}