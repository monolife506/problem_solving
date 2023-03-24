#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_prime[31623];
vector<int> primes;

void precompute()
{
    fill_n(&is_prime[0], sizeof(is_prime), true);
    primes.push_back(2);
    for (ll i = 4; i * i <= 1'000'000'000; i += 2)
        is_prime[i] = false;
    for (ll i = 3; i * i <= 1'000'000'000; i += 2)
    {
        if (!is_prime[i])
            continue;
        primes.push_back(i);
        for (ll j = i * i; j * j <= 1'000'000'000; j += i)
            is_prime[j] = false;
    }
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    set<int> x;
    vector<bool> flag(31623);
    for (int i = 0; i < n; ++i)
    {
        for (int p : primes)
        {
            if (a[i] >= p && a[i] % p == 0)
            {
                if (!flag[p])
                {
                    flag[p] = true;
                    while (a[i] % p == 0)
                        a[i] /= p;
                }
                else
                {
                    cout << "YES" << '\n';
                    return;
                }
            }
        }

        if (a[i] != 1)
        {
            if (x.find(a[i]) == x.end())
            {
                x.insert(a[i]);
            }
            else
            {
                cout << "YES" << '\n';
                return;
            }
        }
    }

    cout << "NO" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    precompute();

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}

/*

x is prime
x <= sqrt(10^9)
cnt of x = 3401

*/