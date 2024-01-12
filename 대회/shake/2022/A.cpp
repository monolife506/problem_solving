#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    int lgn = log2(n);
    int ans = log2(k);
    ans += min(m, (lgn - ans));

    cout << ans << '\n';
}

/*

1 2 3 4 5 6 7 8


*/