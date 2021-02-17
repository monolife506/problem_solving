#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int N;
int A[4000], B[4000], C[4000], D[4000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll ans = 0;
    vector<int> v;

    cin >> N;
    for (size_t i = 0; i < N; i++)
        cin >> A[i] >> B[i] >> C[i] >> D[i];

    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < N; j++)
            v.push_back(C[i] + D[j]);

    sort(v.begin(), v.end());

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            int sum = A[i] + B[j];
            auto lo = lower_bound(v.begin(), v.end(), -sum);
            auto hi = upper_bound(v.begin(), v.end(), -sum);
            ans += (ll)(hi - lo);
        }
    }

    cout << ans << '\n';
}