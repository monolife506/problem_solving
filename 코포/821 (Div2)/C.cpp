#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> a[i];

        bool flag = true;
        for (int i = 2; i <= n; ++i)
        {
            if (a[i] < a[i - 1])
                flag = false;
        }

        if (n == 1 || flag)
        {
            cout << 0 << '\n';
        }
        else
        {
            vector<pii> ans;
            ans.push_back({1, n});
            if ((a[1] + a[n]) % 2 == 0)
                a[1] = a[n];
            else
                a[n] = a[1];

            for (int i = 2; i < n; ++i)
            {
                if ((a[i] + a[n]) % 2 == 0)
                {
                    a[i] = a[n];
                    ans.push_back({i, n});
                }
                else // if (a[1] + a[i]) % 2 == 1
                {
                    a[1] = a[i];
                    ans.push_back({1, i});
                }
            }

            cout << ans.size() << '\n';
            for (pii &p : ans)
                cout << p.first << " " << p.second << '\n';
        }
    }
}

/*

1 10 3 0 5


*/