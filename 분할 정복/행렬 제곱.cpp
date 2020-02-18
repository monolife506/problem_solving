// 10830번: 행렬 제곱

#include <iostream>
#include <array>
using namespace std;
typedef unsigned long long ll;

size_t N;
array<array<int, 5>, 5> input;

array<array<int, 5>, 5> matrix_mod(ll K)
{
    if (K == 1)
        return input;

    array<array<int, 5>, 5> result;
    array<array<int, 5>, 5> half = matrix_mod(K / 2);
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            int sum = 0;
            for (size_t k = 0; k < N; k++)
                sum = (((half[i][k] * half[k][j]) % 1000) + (sum % 1000)) % 1000;
            result[i][j] = sum;
        }
    }
    if (K % 2)
    {
        half = result;
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < N; j++)
            {
                int sum = 0;
                for (size_t k = 0; k < N; k++)
                    sum = (((half[i][k] * input[k][j]) % 1000) + (sum % 1000)) % 1000;
                result[i][j] = sum;
            }
        }
    }
    return result;
}

int main()
{
    ll B;
    cin >> N >> B;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cin >> input[i][j];
            if (input[i][j] == 1000)
                input[i][j] = 0;
        }
    }

    array<array<int, 5>, 5> ans = matrix_mod(B);
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
            cout << ans[i][j] << " ";
        cout << '\n';
    }
}
