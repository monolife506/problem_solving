#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, a[1000000];

bool f(int k)
{
    deque<pii> dq;
    for (int i = 0; i < k; ++i)
    {
        if (dq.empty() || a[i] >= dq.front().first)
        {
            dq.push_front({a[i], i});
        }
        else
        {
            while (!dq.empty() && dq.back().first < a[i])
                dq.pop_back();
            dq.push_back({a[i], i});
        }
    }

    for (int i = k; i < n; ++i)
    {
        int prev_val = dq.front().first;

        while (!dq.empty() && dq.front().second <= i - k)
            dq.pop_front();
        while (!dq.empty() && dq.back().second <= i - k)
            dq.pop_back();

        if (dq.empty() || a[i] >= dq.front().first)
        {
            dq.push_front({a[i], i});
        }
        else
        {
            while (!dq.empty() && (dq.back().first < a[i] || dq.back().second <= i - k))
                dq.pop_back();
            dq.push_back({a[i], i});
        }

        if (dq.front().first < prev_val)
            return false;
    }

    return true;
}

ll parametric_search(int l, int r)
{
    int ret;
    int mid;

    while (l <= r)
    {
        mid = (l + r) / 2;
        if (f(mid))
        {
            ret = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cout << parametric_search(1, n) << '\n';
}