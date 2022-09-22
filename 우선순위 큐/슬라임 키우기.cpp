#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    vector<ll> tmp, ans;
    for (int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;
        pq.push(a);
    }
    for (int i = 0; i < Q; ++i)
    {
        int x, y;
        cin >> x >> y;
        while (!pq.empty() && pq.top() <= x)
        {
            ll top = pq.top();
            pq.pop();

            if (top * y <= 0 || top * y >= (int)1e9)
                ans.push_back(top * y);
            else
                tmp.push_back(top * y);
        }
        while (!tmp.empty())
        {
            pq.push(tmp.back());
            tmp.pop_back();
        }
    }

    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }

    sort(ans.begin(), ans.end());
    for (ll num : ans)
        cout << num << " ";

    cout << '\n';
}