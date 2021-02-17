#include <cmath>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
const ll MAX_I = 55;

ll dp[MAX_I];

ll getCnt(ll num)
{
    ll cnt = 0;
    ll one_cnt = 0;

    string str;
    while (num != 0) {
        str += (num % 2 == 0 ? "0" : "1");
        num /= 2;
    }

    for (int i = str.size() - 1; i >= 0; i--) {
        if (str[i] == '1') {
            cnt += dp[i] + ((ll)pow(2, i) * one_cnt);
            one_cnt++;
        }
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    dp[0] = 1;
    for (ll i = 1; i < MAX_I; i++)
        dp[i] = 2 * (dp[i - 1] - 1) + (ll)pow(2, i - 1) + 1;

    ll A, B;
    cin >> A >> B;
    cout << getCnt(B) - getCnt(A - 1);
}

// 0
// 1 (1)
// 10 (2)
// 11
// 100 (5)
// 101
// 110
// 111
// 1000 (13)
// 1001
// 1010
// 1011
// 1100 (22)
// 1101 (25)
// 1110
// 1111 (32)

// 1100 = 5 + 4
// 1000 = 13

// 1111 = 1 + 1 * 3
// 1110 = 2 + 2 * 2
// 1100 = 5 + 4 * 1
// 1000 = 13
