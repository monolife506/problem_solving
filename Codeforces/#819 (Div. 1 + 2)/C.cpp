#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int root[200001];
bool flag[200001];

int find(int n)
{
    return (root[n] == -1) ? n : root[n] = find(root[n]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
        root[b] = a;
}

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    for (int i = 0; i < n * 2; ++i)
    {
        root[i] = -1;
        flag[i] = false;
    }

    stack<pii> st;
    int depth = 0;
    for (int i = 0; i < n * 2; ++i)
    {
        if (s[i] == '(')
        {
            st.push({i, depth++});
        }
        else
        {
            while (depth - 1 != st.top().second)
            {
                merge(i - 1, st.top().first);
                st.pop();
            }

            merge(i, st.top().first);
            depth--;
        }
    }

    while (!st.empty())
    {
        merge(n * 2 - 1, st.top().first);
        st.pop();
    }

    int ans = 0;
    for (int i = 0; i < n * 2; ++i)
    {
        if (!flag[find(i)])
        {
            flag[find(i)] = true;
            ans++;
        }
    }

    cout << ans << '\n';
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

()(()())()

1
9
(())(((())))(()())

6

*/
