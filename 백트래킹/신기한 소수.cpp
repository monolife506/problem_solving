#include <iostream>
using namespace std;

int N;

bool is_prime(int num)
{
    if (num == 1)
        return false;

    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

void backtracking(int num, int d)
{
    if (!is_prime(num))
        return;

    if (d == N)
    {
        cout << num << '\n';
        return;
    }

    for (int i = 0; i <= 9; ++i)
        backtracking(num * 10 + i, d + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= 9; ++i)
        backtracking(i, 1);
}