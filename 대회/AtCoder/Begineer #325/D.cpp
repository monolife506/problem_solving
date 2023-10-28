#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    map<ll, vector<ll>> times;
    vector<ll> in;
    for (int i = 0; i < n; ++i)
    {
        ll t, d;
        cin >> t >> d;
        times[t].push_back(t + d);
        in.push_back(t);
    }

    sort(in.begin(), in.end());
    in.erase(unique(in.begin(), in.end()), in.end());
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    int ans = 0;
    for (int i = 0; i < in.size(); ++i)
    {
        while (!pq.empty() && pq.top() < in[i])
            pq.pop();

        for (ll j : times[in[i]])
            pq.push(j);

        if (i != in.size() - 1)
        {
            for (ll j = in[i]; j < in[i + 1]; ++j)
            {
                while (!pq.empty() && pq.top() < j)
                    pq.pop();
                if (pq.empty())
                    break;

                if (pq.top() >= j)
                    ans++;

                pq.pop();
            }
        }
        else
        {
            ll cur = in.back();
            while (!pq.empty())
            {
                while (!pq.empty() && pq.top() < cur)
                    pq.pop();
                if (pq.empty())
                    break;

                if (pq.top() >= cur)
                    ans++;

                pq.pop();
                cur++;
            }
        }
    }

    cout << ans << '\n';
}

/*

1 2 v
1 2 v
2 3 v
2 3
3 4 v
3 4
*/