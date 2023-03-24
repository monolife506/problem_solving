#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    string a, b;
    cin >> a >> b;

    if (a.back() == b.back())
    {
        if (a.back() == 'S')
        {
            if (a.size() > b.size())
                cout << '<' << '\n';
            else if (a.size() == b.size())
                cout << '=' << '\n';
            else
                cout << '>' << '\n';
        }
        else if (a.back() == 'M')
        {
            cout << '=' << '\n';
        }
        else // a.back() == 'L'
        {
            if (a.size() > b.size())
                cout << '>' << '\n';
            else if (a.size() == b.size())
                cout << '=' << '\n';
            else
                cout << '<' << '\n';
        }
    }
    else
    {
        if (a.back() == 'L')
        {
            cout << '>' << '\n';
        }
        else if (b.back() == 'L')
        {
            cout << '<' << '\n';
        }
        else if (a.back() == 'M')
        {
            cout << '>' << '\n';
        }
        else // b.back() == 'M'
        {
            cout << '<' << '\n';
        }
    }
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

l s m

*/