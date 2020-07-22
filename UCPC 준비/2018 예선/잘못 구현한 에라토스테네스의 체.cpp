#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll N, cnt = 0;
    cin >> N;
    for (ll i = N; i != 0; i = (N - 1) / (((N - 1) / i) + 1))
        cnt += ((N - 1) / i + 1) * (i - ((N - 1) / (((N - 1) / i) + 1)));

    cout << cnt;
}

// 12
// 12 + (11 + 5 + 3 + 2 + 2 + 1 + 1 + 1 + 1 + 1 + 1) == 41

// 3
// 3 + (2 + 1) == 6
