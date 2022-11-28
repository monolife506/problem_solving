#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[1000000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int m = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        m += a[i];
    }

    int d1 = 0, d2 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > m / n + 1)
            d1 += a[i] - (m / n + 1);
        if (a[i] < m / n)
            d2 += m / n - a[i];
    }

    cout << max(d1, d2) << '\n';
}

/*


2
4 2

4
2 4 2 2

2 2 3 3

*/