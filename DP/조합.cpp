// 2407번: 조합

#include <iostream>
using namespace std;

struct BigInt
{
    int value[30];
    BigInt(int init = 1)
    {
        for (int i = 29; i >= 0; i--)
        {
            value[i] = init % 10;
            init /= 10;
        }
    }

    BigInt operator+(const BigInt &arg)
    {
        BigInt tmp;
        int carry = 0;

        for (int i = 29; i >= 0; i--)
        {
            tmp.value[i] = this->value[i] + arg.value[i] + carry;
            carry = tmp.value[i] / 10;
            tmp.value[i] %= 10;
        }

        return tmp;
    }
};

ostream &operator<<(ostream &output, const BigInt &bigint)
{
    int i;
    for (i = 0; (i < 30) && (bigint.value[i] == 0); ++i)
    {
    }

    if (i == 30)
        output << 0;
    else
    {
        for (; i < 30; i++)
            output << bigint.value[i];
    }

    return output;
}

BigInt dp[101][101];

int main()
{
    int n, m;
    cin >> n >> m;
    for (size_t i = 2; i <= 100; i++)
        for (size_t j = 1; j < i; j++)
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

    cout << dp[n][m];
}