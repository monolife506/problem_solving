#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;

const int MAX_N = 1e5;
const int MAX_T = 1e5;
const int MAX_A = 1e6;

struct Query
{
    int idx, l, r;
    Query(int idx = 0, int l = 0, int r = 0) : idx(idx), l(l), r(r) {}
};

size_t n, t;
int a[MAX_N + 1];
Query query[MAX_T];

int cnt[MAX_A + 1];
ll result[MAX_T];

void offline_query()
{
    int sqrt_n = sqrt(n);
    sort(query, query + t,
         [sqrt_n](Query &lhs, Query &rhs) -> bool
         {
             if (lhs.l / sqrt_n != rhs.l / sqrt_n)
                 return lhs.l / sqrt_n < rhs.l / sqrt_n;
             else
                 return lhs.r < rhs.r;
         });

    ll total = 0;
    int l = query[0].l, r = query[0].r;
    for (size_t i = l; i <= r; ++i)
    {
        total -= 1LL * cnt[a[i]] * cnt[a[i]] * a[i];
        total += 1LL * (cnt[a[i]] + 1) * (cnt[a[i]] + 1) * a[i];
        ++cnt[a[i]];
    }

    result[query[0].idx] = total;
    for (size_t i = 1; i < t; ++i)
    {
        while (l < query[i].l)
        {
            total -= 1LL * cnt[a[l]] * cnt[a[l]] * a[l];
            total += 1LL * (cnt[a[l]] - 1) * (cnt[a[l]] - 1) * a[l];
            --cnt[a[l]];
            ++l;
        }
        while (l > query[i].l)
        {
            --l;
            total -= 1LL * cnt[a[l]] * cnt[a[l]] * a[l];
            total += 1LL * (cnt[a[l]] + 1) * (cnt[a[l]] + 1) * a[l];
            ++cnt[a[l]];
        }
        while (r < query[i].r)
        {
            ++r;
            total -= 1LL * cnt[a[r]] * cnt[a[r]] * a[r];
            total += 1LL * (cnt[a[r]] + 1) * (cnt[a[r]] + 1) * a[r];
            ++cnt[a[r]];
        }
        while (r > query[i].r)
        {
            total -= 1LL * cnt[a[r]] * cnt[a[r]] * a[r];
            total += 1LL * (cnt[a[r]] - 1) * (cnt[a[r]] - 1) * a[r];
            --cnt[a[r]];
            --r;
        }

        result[query[i].idx] = total;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> t;
    for (size_t i = 1; i <= n; ++i)
        cin >> a[i];
    for (size_t i = 0; i < t; ++i)
    {
        cin >> query[i].l >> query[i].r;
        query[i].idx = i;
    }

    offline_query();
    for (size_t i = 0; i < t; ++i)
        cout << result[i] << '\n';
}

// 9 + 12 + 4