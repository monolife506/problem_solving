#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll A, B;
    cin >> A >> B;

    ll ans = 0;
    while (A != B)
    {
        if (A < B)
            swap(A, B);

        if (A % B != 0)
        {
            ans += A / B;
            A %= B;
        }
        else
        {
            ans += A / B - 1;
            A = B;
        }
    }

    cout << ans << '\n';
}

/*

9 3
6 3
3 3
*/