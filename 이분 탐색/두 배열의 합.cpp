#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll T, N, M, ans;
ll A[1001], B[1001];
vector<ll> sumA, sumB;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T >> N;
    for (size_t i = 1; i <= N; i++)
    {
        ll num;
        cin >> num;
        A[i] = A[i - 1] + num;
    }

    cin >> M;
    for (size_t i = 1; i <= M; i++)
    {
        ll num;
        cin >> num;
        B[i] = B[i - 1] + num;
    }

    for (size_t i = 0; i < N; i++)
        for (size_t j = i + 1; j <= N; j++)
            sumA.push_back(A[j] - A[i]);

    for (size_t i = 0; i < M; i++)
        for (size_t j = i + 1; j <= M; j++)
            sumB.push_back(B[j] - B[i]);

    sort(sumB.begin(), sumB.end());
    for (ll num : sumA)
    {
        auto low = lower_bound(sumB.begin(), sumB.end(), T - num);
        auto hi = upper_bound(sumB.begin(), sumB.end(), T - num);
        ans += (ll)(hi - low);
    }

    cout << ans;
}

// 2개의 prefix sum
// (A[i] - A[j]) + (B[k] - B[l]) == T
// 순서쌍 (i, j, k, l)의 개수 (i < j, k < l)

// 5
// 1 4 5 7
// 1 4 6