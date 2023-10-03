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

    int n;
    cin >> n;

    vector<pii> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        a[i].second = i;
    }

    int ans = INT32_MAX;
    for (int i = 0; i < n - 1; ++i)
    {
        int num1 = a[i].first;
        int num2 = a[i + 1].first;

        if (num1 > num2)
            swap(num1, num2);

        if (num2 >= num1 * 2)
        {
            ans = min(ans, (num2 / 2) + (num2 % 2));
            continue;
        }

        int tmp = 0;
        if (num2 - num1 > 0)
        {
            tmp += (num2 - num1);
            num2 - (num2 - num1) * 2;
            num1 = num2;
        }

        tmp += (num1 + num2) / 3;
        if ((num1 + num2) % 3 != 0)
            tmp++;

        ans = min(ans, tmp);
    }
    for (int i = 0; i < n - 2; ++i)
    {
        int num1 = a[i].first;
        int num2 = a[i + 2].first;
        ans = min(ans, min(num1, num2) + (abs(num1 - num2) / 2) + (abs(num1 - num2) % 2));
    }

    sort(a.begin(), a.end());
    if (abs(a[0].second - a[1].second) >= 2)
    {
        int num1 = a[0].first;
        int num2 = a[1].first;
        ans = min(ans, (num1 / 2) + (num1 % 2) + (num2 / 2) + (num2 % 2));
    }

    cout << ans << '\n';
}

/*

6 0
8 2
10 1

4 4
2 3
1 1
0 0

5 5
3 4
2 2
1 0
0 0

*/