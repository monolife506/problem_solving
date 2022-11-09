#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200001], pxor[200001], last[200001];
ll psum[200001];
map<int, int> even, odd;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;

    even[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
        pxor[i] = pxor[i - 1] ^ a[i];

        if (i % 2 == 0)
        {
            if (odd.find(pxor[i]) != odd.end())
                last[i] = odd[pxor[i]];

            even[pxor[i]] = i;
        }
        else
        {
            if (even.find(pxor[i]) != even.end())
                last[i] = even[pxor[i]];

            odd[pxor[i]] = i;
        }
    }

    for (int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;

        if ((pxor[r] ^ pxor[l - 1]) != 0)
            cout << -1 << '\n';
        else if (psum[r] - psum[l - 1] == 0)
            cout << 0 << '\n';
        else if ((r - l + 1) % 2 == 1)
            cout << 1 << '\n';
        else if (a[l] == 0 || a[r] == 0)
            cout << 1 << '\n';
        else if (last[r] >= l)
            cout << 2 << '\n';
        else
            cout << -1 << '\n';
    }
}

/*

홀수 길이의 xor값이 0인 subarray가 존재하는가?

*/