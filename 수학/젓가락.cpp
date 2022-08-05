#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll N, R;
    cin >> N >> R;
    cout << N + (R * 2 - 1) << '\n';
}

/*

R = 1 -> N + 1
R = 2 -> N + 3
R = 3 -> N + 5 ...

*/