#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int D, P, Q;
    cin >> D >> P >> Q;

    if (P < Q)
        swap(P, Q);

    int ans = INT32_MAX;
    for (int x = min((D + P - 1) / P, Q); x >= 0; --x)
    {
        int y = (D - P * x > 0) ? (D - P * x + Q - 1) / Q : 0;
        ans = min(ans, P * x + Q * y);
    }

    cout << ans << '\n';
}

/*

Px + Qy >= D일 때 x, y가 음이 아닌 정수인 경우 Px + Qy의 최솟값
P(Q + k) -> Pk + QP

*/