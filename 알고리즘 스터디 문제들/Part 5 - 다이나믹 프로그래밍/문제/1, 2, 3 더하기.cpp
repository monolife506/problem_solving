#include <iostream>
#include <array>
using namespace std;

array<int, 11 + 1> memo = {};

int main()
{
    memo[0] = 1;
    for (int i = 1; i <= 11; i++)
    {
        if (i - 3 >= 0)
            memo[i] += memo[i - 3];
        if (i - 2 >= 0)
            memo[i] += memo[i - 2];
        if (i - 1 >= 0)
            memo[i] += memo[i - 1];
    }

    size_t T, N;
    cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        cin >> N;
        cout << memo[N] << '\n';
    }
}