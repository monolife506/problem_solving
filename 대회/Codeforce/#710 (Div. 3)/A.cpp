#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
    size_t T;
    cin >> T;
    for (size_t tc = 0; tc < T; tc++) {
        ll n, m, x;
        cin >> n >> m >> x;

        ll row = (x - 1) % n;
        ll col = (x - 1) / n;

        cout << (row * m) + (col + 1) << '\n';
    }
}