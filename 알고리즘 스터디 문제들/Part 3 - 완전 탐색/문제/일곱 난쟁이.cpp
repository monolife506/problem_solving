#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main()
{
    array<int, 9> N;
    array<int, 7> M;
    for (size_t i = 0; i < 9; i++)
        cin >> N[i];

    int sum;
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = i + 1; j < 9; j++)
        {
            sum = 0;
            for (size_t k = 0; k < 9; k++)
            {
                if (k != i && k != j)
                    sum += N[k];
            }

            if (sum == 100)
            {
                int index = 0;
                for (size_t k = 0; k < 9; k++)
                {
                    if (k != i && k != j)
                        M[index++] = N[k];
                }
                break;
            }
        }

        if (sum == 100)
            break;
    }

    sort(M.begin(), M.end());
    for (size_t i = 0; i < 7; i++)
        cout << M[i] << '\n';
}