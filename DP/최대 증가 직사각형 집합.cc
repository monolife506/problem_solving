#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct SegmentTree
{
    size_t sz;
    vector<int> tree;

    SegmentTree(const size_t sz) : sz(sz)
    {
        tree.resize(sz * 4, 0);
    }

    void update(int cur, int l, int r, int idx, int val)
    {
        if (l > idx || r < idx)
            return;

        if (l == r)
        {
            tree[cur] = val;
            return;
        }

        update(cur * 2, l, (l + r) / 2, idx, val);
        update(cur * 2 + 1, (l + r) / 2 + 1, r, idx, val);
        tree[cur] = max(tree[cur * 2], tree[cur * 2 + 1]);
    }

    void update(int idx, int val) { return update(1, 1, sz, idx, val); }

    int get_max(int cur, int l, int r, int L, int R)
    {
        if (l > R || r < L)
            return INT32_MIN;
        if (l >= L && r <= R)
            return tree[cur];

        return max(get_max(cur * 2, l, (l + r) / 2, L, R),
                   get_max(cur * 2 + 1, (l + r) / 2 + 1, r, L, R));
    }

    int get_max(int L, int R) { return get_max(1, 1, sz, L, R); }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<pii, pii>> rect(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> rect[i].first.first >> rect[i].first.second;
        cin >> rect[i].second.first >> rect[i].second.second;

        rect[i].first.first += 2;
        rect[i].first.second += 2;
        rect[i].second.first += 2;
        rect[i].second.second += 2;
    }

    sort(rect.begin(), rect.end(),
         [](pair<pii, pii> &a, pair<pii, pii> &b)
         {
             if (a.first.first != b.first.first)
                 return a.first.first < b.first.first;
             else
                 return a.second.first < b.second.first;
         });

    int ans = 1;
    SegmentTree tree(100'002);
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    for (int i = 1; i <= n; ++i)
    {
        auto [p1, p2] = rect[i];
        auto [x1, y1] = p1;
        auto [x2, y2] = p2;

        while (!pq.empty() && pq.top().first < x1)
        {
            auto [y, val] = pq.top().second;
            tree.update(y, max(val, tree.get_max(y, y)));
            pq.pop();
        }

        auto max_val = tree.get_max(1, y1 - 1);
        ans = max(ans, max_val + 1);
        pq.push({x2, {y2, max_val + 1}});
    }

    cout << ans << '\n';
}

/*

2
0 0 2 1
1 2 3 3

1

to 1d


*/