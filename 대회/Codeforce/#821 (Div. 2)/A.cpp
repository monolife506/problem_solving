#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        int n, k;
        cin >> n >> k;

        vector<int> selected(k);
        for (int i = 1; i <= n; ++i)
        {
            int a;
            cin >> a;
            if (selected[i % k] < a)
                selected[i % k] = a;
        }

        ll ans = 0;
        for (int num : selected)
            ans += num;

        cout << ans << '\n';
    }
}