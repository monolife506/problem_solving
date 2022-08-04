#include <iostream>
using namespace std;
typedef long long ll;

int T[100000];

ll gcd(ll a, ll b)
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

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    ll ans;
    if (N == 3)
    {
        cin >> ans;
        cout << ans << '\n';
    }
    else
    {
        cin >> T[0] >> T[1];

        ans = lcm(T[0], T[1]);
        for (int i = 2; i < N - 2; ++i)
        {
            cin >> T[i];
            ans = lcm(ans, T[i]);
        }

        cout << ans << '\n';
    }
}