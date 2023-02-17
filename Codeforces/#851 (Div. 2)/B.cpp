#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    string n;
    cin >> n;

    vector<int> x, y;
    bool flag = true;
    for (int i = 0; i < n.length(); ++i)
    {
        int num = n[i] - '0';
        if (num % 2 == 0)
        {
            x.push_back(num / 2);
            y.push_back(num / 2);
        }
        else
        {
            if (flag)
            {
                x.push_back(num / 2 + 1);
                y.push_back(num / 2);
                flag = false;
            }
            else
            {
                x.push_back(num / 2);
                y.push_back(num / 2 + 1);
                flag = true;
            }
        }
    }

    bool leading_zero = true;
    for (int c : x)
    {
        if (c != 0)
            leading_zero = false;
        if (leading_zero)
            continue;

        cout << c;
    }

    if (leading_zero)
        cout << 0 << " ";
    else
        cout << " ";

    leading_zero = true;
    for (int c : y)
    {
        if (c != 0)
            leading_zero = false;
        if (leading_zero)
            continue;

        cout << c;
    }

    if (leading_zero)
        cout << 0 << '\n';
    else
        cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}

/*

1 - 1 0
2 - 1 1
3 - 2 1
4 -
...


1206
1103
0103


*/