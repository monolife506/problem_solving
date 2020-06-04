// 1629번: 곱셈

#include <iostream>
using namespace std;
typedef unsigned long long ll;

ll ans(ll A, ll B, ll C)
{
    if (B == 1)
        return A % C;
    else
    {
        ll total = (ans(A, B / 2, C) * ans(A, B / 2, C)) % C;
        if (B % 2)
            total = ((A % C) * total) % C;
        return total;
    }
}

int main()
{
    ll A, B, C;
    cin >> A >> B >> C;
    cout << ans(A, B, C);
}