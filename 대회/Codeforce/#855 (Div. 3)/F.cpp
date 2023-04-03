#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int m1[200000], m2[200000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        for (char c : s)
        {
            m1[i] |= (1 << (c - 'a'));
            m2[i] ^= (1 << (c - 'a'));
        }
    }

    ll ans = 0;
    for (int i = 0; i < 26; ++i)
    {
        map<int, int> cnt;
        for (int j = 0; j < n; ++j)
        {
            if (!(m1[j] & (1 << i)))
                cnt[m2[j]]++;
        }

        int target = ((1 << 26) - 1) ^ (1 << i);
        for (int j = 0; j < n; ++j)
        {
            if (!(m1[j] & (1 << i)))
                ans += cnt[m2[j] ^ target];
        }
    }

    cout << ans / 2 << '\n';
}

/*

1 = odd
0 = even

a ^ a ^ b = c ^ a

*/