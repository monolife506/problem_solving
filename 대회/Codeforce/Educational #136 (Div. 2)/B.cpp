#include <iostream>
#include <vector>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> d(n), a(n);
    for (int i = 0; i < n; ++i)
        cin >> d[i];

    bool flag = true;

    a[0] = d[0];
    for (int i = 1; i < n; ++i)
    {
        if (d[i] == 0)
        {
            a[i] = a[i - 1];
        }
        else if (a[i - 1] - d[i] >= 0)
        {
            flag = false;
            break;
        }
        else
        {
            a[i] = a[i - 1] + d[i];
        }
    }

    if (flag)
    {
        for (int i = 0; i < n; ++i)
            cout << a[i] << " ";

        cout << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solve();
}

/*

1
1
3 (-2)
8 (-2)

2
8 (-6)
11, 5

*/