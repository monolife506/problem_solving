#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool is_prime[51];
vector<int> primes;

void sieve()
{
    fill_n(&is_prime[0], 51, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= 50; ++i)
    {
        if (!is_prime[i])
            continue;
        primes.push_back(i);
        for (int j = i * i; j <= 50; j += i)
            is_prime[j] = false;
    }
}

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i + 1 < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (a[i] == a[j])
            {
                cout << "NO" << '\n';
                return;
            }
        }
    }

    for (int p : primes)
    {
        vector<int> cnt(p, 0);
        for (int i = 0; i < n; ++i)
            cnt[a[i] % p]++;

        if (*min_element(cnt.begin(), cnt.end()) >= 2)
        {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    sieve();

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}

/*

2
5
2 * 5

*/