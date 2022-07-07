#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

ll A[500000], B[500000];

ll get_gcd(ll a, ll b)
{
    ll r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

bool is_square(ll n)
{
    ll l = 1;
    ll r = 1e9;
    ll mid;

    while (l <= r)
    {
        mid = (l + r) / 2;
        if (n == mid * mid)
            return true;
        else if (n > mid * mid)
            l = mid + 1;
        else // n < mid * mid
            r = mid - 1;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
        B[i] = A[i];
    }

    sort(B, B + N);

    bool flag = true;
    for (int i = 0; i < N; ++i)
    {
        ll gcd = get_gcd(A[i], B[i]);
        if (!is_square(A[i] / gcd) || !is_square(B[i] / gcd))
        {
            flag = false;
            break;
        }
    }

    cout << (flag ? "YES" : "NO") << '\n';
}