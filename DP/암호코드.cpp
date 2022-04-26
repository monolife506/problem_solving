#include <iostream>
#include <string>
using namespace std;

const int MOD = 1e6;

int cache[5001];

bool decode_one(string &pwd, int i)
{
    return (pwd[i] - '0') != 0;
}

bool decode_two(string &pwd, int i)
{
    int num = 10 * (pwd[i] - '0') + (pwd[i + 1] - '0');
    return num >= 10 && num <= 26;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string pwd;
    cin >> pwd;

    cache[0] = decode_one(pwd, 0);
    if (pwd.length() != 1)
        cache[1] = (decode_one(pwd, 0) && decode_one(pwd, 1)) + decode_two(pwd, 0);

    for (size_t i = 2; i < pwd.length(); ++i)
    {
        if (decode_one(pwd, i))
            cache[i] += cache[i - 1];
        if (decode_two(pwd, i - 1))
            cache[i] += cache[i - 2];

        cache[i] %= MOD;
    }

    cout << cache[pwd.length() - 1] << '\n';
}