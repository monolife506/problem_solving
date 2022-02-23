#include <algorithm>
#include <iostream>
using namespace std;

int a[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int x, lo = 0, hi = n - 1, ans = 0;
    cin >> x;

    sort(a, a + n);
    while (lo < hi)
    {
        if (a[lo] + a[hi] == x)
        {
            ++ans;
            ++lo;
            --hi;
            continue;
        }

        (a[lo] + a[hi] < x) ? ++lo : --hi;
    }

    cout << ans << '\n';
}

/*
1 2 3 5 7 9 10 11 12
*/