#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<P> p;
    vector<int> r;
    for (int i = 0; i < N; ++i)
    {
        int L, R;
        cin >> L >> R;
        p.push_back({L, R});
        r.push_back(R);
    }

    sort(p.begin(), p.end());

    int cur = 0, d = 0;
    for (int i = 0; i < N; ++i)
    {
        if (cur >= p[i].first && cur < p[i].second)
        {
            d += p[i].second - cur;
            cur = p[i].second;
        }
        else if (cur < p[i].first)
        {
            p.push_back({cur, cur + d});
            cur = p[i].second;
            d = p[i].second - p[i].first;
        }
    }

    p.push_back({cur, cur + d});
    sort(p.begin(), p.end());

    cur = 0;
    for (int i = 0; i < p.size(); ++i)
    {
        if (cur >= p[i].first && cur < p[i].second)
            cur = p[i].second;
        else if (cur < p[i].first)
            break;
    }

    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        if (cur >= r[i])
            ans = max(ans, r[i]);
    }

    cout << ans << '\n';
}

/*

3
0 10
11 12
15 17

17

*/