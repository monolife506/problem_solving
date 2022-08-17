#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll N, M, a, K;
    cin >> N >> M >> a >> K;
    cout << min(N - 1, a - K) + 1 << " " << ((a - K + M - 1) / M) + 1 << '\n';
}

/*

30 5

51 3
ceil(48 / 5) = 10
min(29, 48)

*/