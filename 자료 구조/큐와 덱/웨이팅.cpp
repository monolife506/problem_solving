#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t[200001], flag[200001];
vector<int> v[200001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(flag, -1, sizeof(flag));

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int t1, t2;
        cin >> t1 >> t2;
        t[t1] = t2;
        v[t[t1]].push_back(t1);
    }

    for (int i = 1; i <= 200000; ++i)
        sort(v[i].begin(), v[i].end());

    int ans = 0;
    queue<int> q;
    for (int i = 1; i <= 200000; ++i)
    {
        for (int num : v[i])
        {
            q.push(num);
            flag[num] = 0;
        }

        if (flag[i] == 0)
        {
            flag[i] = 1;
            ans = max(ans, i - t[i]);
        }
        else
        {
            while (!q.empty() && flag[q.front()] == 1)
                q.pop();

            if (!q.empty())
            {
                int cur = q.front();
                q.pop();

                flag[cur] = 1;
                ans = max(ans, i - t[cur]);
            }
        }
    }

    for (int i = 200001; !q.empty(); i++)
    {
        while (!q.empty() && flag[q.front()] == 1)
            q.pop();

        if (!q.empty())
        {
            int cur = q.front();
            q.pop();

            flag[cur] = 1;
            ans = max(ans, i - t[cur]);
        }
    }

    cout << ans << '\n';
}