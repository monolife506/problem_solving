#include <iostream>
using namespace std;

int cnt1, cnt2;

int fib1(int n)
{
    if (n == 1 || n == 2)
    {
        ++cnt1;
        return 1;
    }

    return fib1(n - 1) + fib1(n - 2);
}

int fib2(int n)
{
    static int cache[41];
    cache[1] = cache[2] = 1;
    for (int i = 3; i <= n; ++i)
    {
        ++cnt2;
        cache[i] = cache[i - 1] + cache[i - 2];
    }

    return cache[n];
}

int main()
{
    int n;
    cin >> n;

    fib1(n);
    fib2(n);
    cout << cnt1 << " " << cnt2 << '\n';
}