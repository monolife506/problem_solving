#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> h(N);
    vector<int> diff(N - 1);
    for (int i = 0; i < N; ++i)
        cin >> h[i];
    for (int i = 0; i < N - 1; ++i)
        diff[i] = h[i + 1] - h[i];

    sort(diff.begin(), diff.end());

    ll ans = 0;
    for (int i = 0; i < N - K; ++i)
        ans += diff[i];

    cout << ans << '\n';
}

/*

2 2 1 4

*/