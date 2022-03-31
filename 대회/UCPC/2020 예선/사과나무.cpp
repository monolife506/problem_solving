#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, oneCnt = 0, twoCnt = 0;
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        oneCnt += (num % 2);
        twoCnt += (num / 2);
    }

    cout << ((twoCnt >= oneCnt && (twoCnt - oneCnt) % 3 == 0) ? "YES" : "NO");
}
// 0 0 T
// 1 3 F
// 0 5550 T
// 5 2 F
//
