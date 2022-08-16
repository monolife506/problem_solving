#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int a[100000], b[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> a[i] >> b[i];

    sort(a, a + N);

    ll ans = 0;
    for (int i = 0; i < N; ++i)
    {
        ans += 1LL * a[i] * (i + 1);
        ans += b[i];
    }

    cout << ans << '\n';
}