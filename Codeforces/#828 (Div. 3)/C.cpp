#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 987654321;

void solve()
{
    int n;
    char c;
    cin >> n >> c;

    string s;
    cin >> s;

    if (c == 'g')
    {
        cout << 0 << '\n';
    }
    else
    {
        vector<int> d(n, INF);

        stack<int> st;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == c)
            {
                st.push(i);
            }
            else if (s[i] == 'g')
            {
                while (!st.empty())
                {
                    d[st.top()] = min(d[st.top()], abs(i - st.top()));
                    st.pop();
                }
            }
        }

        if (!st.empty())
        {
            for (int i = 0; i < n; ++i)
            {
                if (s[i] == 'g')
                {
                    while (!st.empty())
                    {
                        d[st.top()] = min(d[st.top()], abs(i + (n - st.top())));
                        st.pop();
                    }

                    break;
                }
            }
        }

        int ans = -1;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == c)
                ans = max(ans, d[i]);
        }

        cout << ans << '\n';
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