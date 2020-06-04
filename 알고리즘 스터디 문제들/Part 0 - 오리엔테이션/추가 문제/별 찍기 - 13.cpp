#include <iostream>
using namespace std;

int main()
{
    size_t N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (size_t j = 0; j < i + 1; j++)
            cout << "*";
        cout << '\n';
    }
    for (int i = N - 2; i >= 0; i--)
    {
        for (size_t j = 0; j < i + 1; j++)
            cout << "*";
        cout << '\n';
    }
}