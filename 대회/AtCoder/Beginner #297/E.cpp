#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    set<ll> s;
    s.insert(0);

    ll ans = 0;
    int nth = 0;
    while (nth != K)
    {
        ll num = *s.begin();
        s.erase(s.begin());
        for (int i = 0; i < N; ++i)
            s.insert(num + A[i]);

        ans = *s.begin();
        nth++;
    }

    cout << ans << '\n';
}

/*


20 30 50

20 20 20







*/