#include <iostream>
#include <vector>
using namespace std;

bool is_prime[1'000'001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fill_n(&is_prime[0], 1'000'001, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= 1'000'000; ++i)
    {
        if (!is_prime[i])
            continue;
        for (int j = i * i; j <= 1'000'000; j += i)
            is_prime[j] = false;
    }

    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        for (int i = 0; i <= n / 2; ++i)
        {
            if (is_prime[i] && is_prime[n - i])
            {
                cout << n << " = " << i << " + " << n - i << '\n';
                break;
            }
        }
    }
}