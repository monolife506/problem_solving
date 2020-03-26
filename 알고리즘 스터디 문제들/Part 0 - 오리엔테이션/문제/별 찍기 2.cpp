#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = N - i; j > 0; j--)
            cout << " ";
        for (size_t k = 0; k < i; k++)
            cout << "*";

        cout << '\n';
    }
}