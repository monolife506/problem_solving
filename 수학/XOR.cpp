#include <iostream>
using namespace std;
typedef long long ll;

ll xor_sum(ll n)
{
    ll m = n % 4;

    if (m == 0)
        return n;
    else if (m == 1)
        return 1;
    else if (m == 2)
        return n + 1;
    else
        return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        ll S, F;
        cin >> S >> F;

        cout << (xor_sum(F) ^ xor_sum(S - 1)) << '\n';
    }
}