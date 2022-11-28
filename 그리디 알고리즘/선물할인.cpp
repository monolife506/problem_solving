#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c[100001];
ll psum[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i)
        cin >> c[i];

    sort(c + 1, c + n + 1);
    for (int i = 1; i <= n; ++i)
        psum[i] = psum[i - 1] + c[i];

    int ans = 0;
    for (int i = 1; i <= b; ++i)
    {
        if (psum[i] / 2 <= a)
            ans = i;
    }
    for (int i = b + 1; i <= n; ++i)
    {
        if (psum[i - b] + (psum[i] - psum[i - b]) / 2 <= a)
            ans = i;
    }

    cout << ans << '\n';
}

/*

2 4 6 8 10

*/