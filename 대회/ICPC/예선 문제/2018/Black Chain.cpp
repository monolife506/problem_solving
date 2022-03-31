#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main()
{
    ll N;
    cin >> N;

    for (ll i = 1;; i++)
    {
        if (N <= (ll)pow(2, i + 1) * (i + 1) - 1)
        {
            cout << i;
            break;
        }
    }
}

// 1 a b => 1 2 4
// 1 1 a b c => 1 1 3 6 12
// 1 1 1 a b c d => 1 1 1 4 8 16 32
// 1 1 1 1 a b c d e => 1 1 1 1 5 10 20 40 80

// Pn == n + (n + 1) + (2n + 2) + (4n + 4) + ... +
// == n + (2^(n + 1) - 1)(n + 1)
// == 2^(n + 1)n -

// n == 2
// (1 + 2 + 4) == 2^3 - 1