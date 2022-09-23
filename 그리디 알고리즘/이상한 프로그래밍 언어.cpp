#include <iostream>
#include <string>
using namespace std;

const __int128_t MOD = 1e9 + 7;
const __int128_t INF = 1e9 * (300001);

void print(__int128_t x)
{
    if (x < 0)
    {
        cout << '-';
        x = -x;
    }

    if (x > 9)
        print(x / 10);

    cout << (char)(x % 10 + '0');
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, k0;
    cin >> N >> k0;

    __int128_t K = k0;
    bool is_inf = false;
    for (int i = 0; i < N; ++i)
    {
        string s1, s2;
        cin >> s1 >> s2;

        if (s1[0] > s2[0]) // '*' < '+' < '-'
            swap(s1, s2);

        __int128_t num1 = stoi(s1.substr(1));
        __int128_t num2 = stoi(s2.substr(1));
        if (s1[0] == '+' && s2[0] == '+')
        {
            K += max(num1, num2);
            if (is_inf)
                K %= MOD;
        }
        else if (s1[0] == '-' && s2[0] == '-')
        {
            if (is_inf)
                K = (K - min(num1, num2) + MOD) % MOD;
            else
                K = max((__int128_t)0, K - min(num1, num2));
        }
        else if (s1[0] == '*' && s2[0] == '*')
        {
            if (num1 == 0 && num2 == 0)
            {
                K = 0;
                is_inf = false;
            }
            else
            {
                K *= max(num1, num2);
                if (is_inf)
                    K %= MOD;
            }
        }
        else if (s1[0] == '+' && s2[0] == '-')
        {
            K += num1;
            if (is_inf)
                K %= MOD;
        }
        else if (s1[0] == '*' && s2[0] == '+')
        {
            if (num1 == 0 || num1 == 1)
            {
                K += num2;
                if (is_inf)
                    K %= MOD;
            }
            else
            {
                if (is_inf)
                {
                    K *= num1;
                    K %= MOD;
                }
                else
                {
                    K = max(K * num1, K + num2);
                }
            }
        }
        else // s1[0] == '*' && s2[0] == '-'
        {
            if (num1 == 0)
            {
                if (is_inf)
                    K = (K - num2 + MOD) % MOD;
                else
                    K = max((__int128_t)0, K - num2);
            }
            else
            {
                K *= num1;
                if (is_inf)
                    K %= MOD;
            }
        }

        if (!is_inf && K >= INF)
        {
            is_inf = true;
            K %= MOD;
        }
    }

    K %= MOD;
    print(K);
    cout << '\n';
}