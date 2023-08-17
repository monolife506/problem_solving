#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    sort(A.begin(), A.end());

    __int128_t ans = 1;
    for (int i = 0; i < N; ++i)
    {
        ans *= A[i];
        if (ans > (ll)1e18)
        {
            cout << -1 << '\n';
            return 0;
        }
    }

    cout << (ll)ans << '\n';
}