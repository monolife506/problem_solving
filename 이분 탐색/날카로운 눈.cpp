#include <iostream>
using namespace std;
typedef long long ll;

int N;
ll A[20000], C[20000], B[20000];

ll getCnt(ll left, ll right)
{
    ll cnt = 0;
    for (size_t i = 0; i < N; i++)
    {
        if (left > C[i] || right < A[i])
            continue;

        ll lo = max(left, A[i]);
        ll hi = min(right, C[i]);
        ll lo_k = ((lo - A[i]) % B[i]) ? (lo - A[i]) / B[i] + 1 : (lo - A[i]) / B[i];
        ll hi_k = (hi - A[i]) / B[i];
        cnt += hi_k - lo_k + 1;
    }

    return cnt;
}

ll parametricSearch()
{
    ll left = 1;
    ll right = INT32_MAX;

    while (left < right)
    {
        ll mid = (left + right) / 2;
        if (getCnt(left, mid) % 2 == 1)
            right = mid;
        else if (getCnt(mid + 1, right) % 2 == 1)
            left = mid + 1;
        else
            return -1; // NOTHING
    }

    return left;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (size_t i = 0; i < N; i++)
        cin >> A[i] >> C[i] >> B[i];

    int ans = parametricSearch();
    if (ans == -1)
        cout << "NOTHING\n";
    else
        cout << ans << " " << getCnt(ans, ans) << '\n';
}