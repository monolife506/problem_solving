// 11689번: GCD(n, k) = 1

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll phi(ll n)
{
    if (n == 1)
        return 1;

    ll ret = n;
    for (ll div = 2; div * div <= n; ++div)
    {
        if (n % div == 0)
        {
            ret /= div;
            ret *= (div - 1);
            while (n % div == 0)
                n /= div;
        }
    }

    if (n > 1)
    {
        ret /= n;
        ret *= n - 1;
    }

    return ret;
}

int main()
{
    ll n;
    cin >> n;
    cout << phi(n) << '\n';
}

/*
오일러 파이 함수
수를 빠르게 소인수분해하고 그에 따라 값 구하기
*/