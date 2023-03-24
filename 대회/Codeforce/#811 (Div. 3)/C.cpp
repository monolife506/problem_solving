#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int s;
    cin >> s;

    int max_d = 9;

    stack<int> st;
    while (s != 0)
    {
        if (s <= max_d)
        {
            st.push(s);
            s -= s;
        }
        else
        {
            s -= max_d;
            st.push(max_d--);
        }
    }

    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }

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

dp[1] = 1
dp[2] = 2
...
dp[9] = 9

dp[10] = 19
dp[11] = 29
dp[12] = 39
...
dp[18] = 189

dp[19] = 289
dp[20] = 389

...
         789

*/