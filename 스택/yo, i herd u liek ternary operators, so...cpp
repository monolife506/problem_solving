#include <iostream>
#include <stack>
#include <string>
using namespace std;
typedef long long ll;

const ll MOD = 1'000'000'007;

ll fac[300001];

ll pow_mod(ll b, ll n)
{
    ll ret = 1;
    b %= MOD;
    while (n > 0)
    {
        if (n % 2 == 1)
            ret = (ret * b) % MOD;
        b = (b * b) % MOD;
        n /= 2;
    }

    return ret;
}

ll catalan_num(ll n)
{
    ll ret = fac[n * 2];
    ret = (ret * pow_mod(fac[n + 1], MOD - 2)) % MOD;
    ret = (ret * pow_mod(fac[n], MOD - 2)) % MOD;
    return ret;
}

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fac[0] = 1;
    for (int i = 1; i <= 300000; ++i)
        fac[i] = (fac[i - 1] * i) % MOD;
}

int main()
{
    init();

    string S;
    cin >> S;

    string S2;
    for (const char &c : S)
    {
        if (c == '?' || c == ':')
            S2.push_back(c);
    }

    int depth = 0;

    stack<pair<int, ll>> s;
    for (int i = 0; i < S2.length(); ++i)
    {
        if (S2[i] == '?')
        {
            ++depth;
        }
        else // S2[i] == ':'
        {
            if (S2[i - 1] == '?')
            {
                s.push({depth, 1});
            }
            else
            {
                ll num = 1, sz = 0;
                while (!s.empty() && s.top().first == depth + 1)
                {
                    num *= s.top().second;
                    num %= MOD;
                    ++sz;
                    s.pop();
                }

                num *= catalan_num(sz);
                num %= MOD;
                s.push({depth, num});
            }

            --depth;
        }
    }

    ll ans = catalan_num(s.size());
    while (!s.empty())
    {
        ans *= s.top().second;
        ans %= MOD;
        s.pop();
    }

    cout << ans << '\n';
}

/*

a?b:c?d:e?f:g

(a?b:(c?d:e))?f:g
((a?b:c)?d:e)?f:g
a?b:(c?d:(e?f:g))
a?b:((c?d:e)?f:g)
(a?b:c)?d:(e?f:g)

? -> (
: -> )

()()

*/