#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX_X = 1e9 + 1;

struct Segment
{
    int i, l, r, c;
    Segment(int i = -1, int l = -1, int r = -1, int c = -1)
        : i(i), l(l), r(r), c(c) {}
};

vector<int> get_dist(int n, vector<Segment> &s)
{
    vector<int> ret(n, MAX_X);

    vector<Segment> sl = s;
    vector<Segment> sr = s;

    sort(sl.begin(), sl.end(),
         [](const Segment &lhs, const Segment &rhs) -> bool
         {
             if (lhs.l != rhs.l)
                 return lhs.l < rhs.l;
             if (lhs.r != rhs.r)
                 return lhs.r < rhs.r;
             else
                 return lhs.c < rhs.c;
         });

    sort(sr.begin(), sr.end(),
         [](const Segment &lhs, const Segment &rhs) -> bool
         {
             if (lhs.r != rhs.r)
                 return lhs.r < rhs.r;
             if (lhs.l != rhs.l)
                 return lhs.l < rhs.l;
             else
                 return lhs.c < rhs.c;
         });

    vector<pii> cur_c;
    vector<vector<pii>> c(n);
    for (int i = 0; i < n; ++i)
    {
        if (cur_c.empty())
        {
            cur_c.push_back({sl[i].r, sl[i].c});
        }
        else if (cur_c.size() == 1)
        {
            if (cur_c[0].second == sl[i].c)
                cur_c[0].first = max(cur_c[0].first, sl[i].r);
            else
                cur_c.push_back({sl[i].r, sl[i].c});
        }
        else // cur_c.size() == 2
        {
            if (cur_c[0].second == sl[i].c)
                cur_c[0].first = max(cur_c[0].first, sl[i].r);
            else if (cur_c[1].second == sl[i].c)
                cur_c[1].first = max(cur_c[1].first, sl[i].r);
            else
                cur_c.push_back({sl[i].r, sl[i].c});
        }

        sort(cur_c.begin(), cur_c.end(), greater<pii>());
        if (cur_c.size() == 3)
            cur_c.pop_back();

        c[i] = cur_c;
    }

    int j = n - 1;
    for (int i = n - 1; i >= 0; --i)
    {
        while (j >= 0 && sl[j].l > sr[i].r)
            --j;

        if (j < 0)
            break;

        if (c[j][0].second != sr[i].c)
            ret[sr[i].i] = min(ret[sr[i].i], max(0, sr[i].l - c[j][0].first));
        else if (c[j].size() == 2)
            ret[sr[i].i] = min(ret[sr[i].i], max(0, sr[i].l - c[j][1].first));
    }

    return ret;
}

void solve()
{
    int n;
    cin >> n;

    vector<Segment> sl(n), sr(n);
    for (int i = 0; i < n; ++i)
    {
        sl[i].i = i;
        cin >> sl[i].l >> sl[i].r >> sl[i].c;
        sr[i] = {sl[i].i, MAX_X - sl[i].r, MAX_X - sl[i].l, sl[i].c};
    }

    vector<int> ld = get_dist(n, sl);
    vector<int> rd = get_dist(n, sr);
    for (int i = 0; i < n; ++i)
        cout << min(ld[i], rd[i]) << " ";

    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc)
        solve();
}

/*

2
1 100 2
10 90 1

0 0

1
3
3 4 1
2 5 1
1 6 2

0 0 0

1
9
15 18 1
20 22 2
13 22 2
13 22 2
3 13 2
6 10 2
3 6 2
19 24 2
22 24 2

0 2 0 0 2 5 9 1 4

1
8
22 26 2
10 16 2
9 10 1
25 25 2
15 22 2
11 18 2
7 13 2
4 14 2

12 0 0 15 5 1 0 0

*/