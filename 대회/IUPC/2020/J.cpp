#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;

ll arr[21];
int num[21];

int main()
{
    ll C, ans = 0;
    cin >> C;

    arr[0] = 1;
    for (size_t i = 1; i < 21; i++)
        arr[i] = arr[i - 1] * 7;

    for (int i = 20; i >= 1; i--) {
        if (C >= arr[i]) {
            num[i] = (C / arr[i]);
            C -= arr[i] * num[i];
        }
    }

    num[0] = C;
    for (size_t i = 0; i <= 20; i++)
        ans += num[i] * (ll)pow(3, i);
    cout << ans;
}

// 7^0 * A + 7^1 * B + 7^2 * C + ...

// 00

// 10

// 20

// 01
// 11
// 21

// 02
// 12
// 22

// 001
// 101
// 201
// 011
// 021

// 002
// 102
// 202
// 012
// 022

// 0001
// 1001
// 2001
// 0101
// 0201
// 0011
// 0021

// 00202

// 2자리 - 6개
// 3자리 -

// 2 6 10 14