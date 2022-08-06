#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int R1, S;
    cin >> R1 >> S;
    cout << 2 * S - R1 << '\n';
}

/*

2 * S = R1 + R2
2 * S - R1 = R2

*/