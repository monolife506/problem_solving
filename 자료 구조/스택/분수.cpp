#include <bits/stdc++.h>
#define endl '\n'
// #define FILE_RW
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void solve()
{
    int n;
    cin >> n;

    vector<char> v(n);
    for (char &vi : v)
        cin >> vi;

    stack<pll> st;
    for (int i = 0; i < n; ++i)
    {
        if (v[i] == '(')
        {
            st.push({0, 0});
        }
        else if (v[i] == ')')
        {
            if (st.size() < 4)
            {
                cout << -1 << endl;
                return;
            }

            pll c = st.top();
            st.pop();
            pll b = st.top();
            st.pop();
            pll a = st.top();
            st.pop();

            if (a.first == 0 || b.first == 0 || c.first == 0 || st.top().first != 0)
            {
                cout << -1 << endl;
                return;
            }

            ll r_gcd = gcd(b.first * c.second, b.second * c.first);
            pll r = {(b.first * c.second) / r_gcd, (b.second * c.first) / r_gcd};
            ll val_gcd = gcd(a.first * r.second + r.first * a.second, a.second * r.second);
            pll val = {(a.first * r.second + r.first * a.second) / val_gcd, (a.second * r.second) / val_gcd};

            st.pop();
            st.push(val);
        }
        else
        {
            st.push({v[i] - '0', 1});
        }
    }

    if (st.size() != 1 || st.top().first == 0)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        cout << st.top().first << " " << st.top().second << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef FILE_RW
    freopen("local.in", "r", stdin);
    freopen("local.out", "w", stdout);
#endif

    solve();
}

/*

a.f   r.f
--- + ---
a.s   r.s

*/