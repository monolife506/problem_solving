// 2293번: 동전 1

#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<int, 100> V;
    array<int, 10000 + 1> DP = {};

    size_t N, K;
    cin >> N >> K;
    for (size_t i = 0; i < N; i++)
        cin >> V[i];

    DP[0] = 1;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 1; j <= K; j++)
        {
            if (j >= V[i])
                DP[j] += DP[j - V[i]];
        }
    }
    cout << DP[K];
}

// 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 2 2 2 2 2 3
// 1 2 2 3 4 5 6 7 8 10