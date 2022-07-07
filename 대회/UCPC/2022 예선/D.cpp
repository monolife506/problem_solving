#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

struct FenwickTree
{
    const size_t sz;
    vector<int> tree;

    FenwickTree(size_t sz) : sz(sz) { tree.resize(sz + 1, 0); }

    void add(int i, int val)
    {
        while (i <= sz)
        {
            tree[i] += val;
            i += (i & -i);
        }
    }

    void add(int l, int r, int val)
    {
        add(l, val);
        if (r < sz)
            add(r + 1, -val);
    }

    int get_sum(int i)
    {
        int ret = 0;
        while (i > 0)
        {
            ret += tree[i];
            i -= (i & -i);
        }

        return ret;
    }
};

int sign(ll n)
{
    return (n > 0) - (n < 0);
}

int get_idx(ll num, vector<ll> &v)
{
    return lower_bound(v.begin(), v.end(), num) - v.begin();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int Q;
    cin >> Q;

    vector<pair<int, P>> q;
    vector<ll> x;

    for (int i = 0; i < Q; ++i)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            ll a, b;
            cin >> a >> b;
            q.push_back({1, {a, b}});

            if (a != 0)
            {
                if (b % a == 0)
                {
                    if (a > 0)
                        x.push_back(-(b / a) - 1);
                    else
                        x.push_back(-(b / a) + 1);
                }
                else
                {
                    ll floor = abs(b) / abs(a);
                    ll ceil = (abs(b) + abs(a) - 1) / abs(a);

                    if (a > 0)
                    {
                        if (sign(a) != sign(b))
                            x.push_back(floor);
                        else
                            x.push_back(-ceil);
                    }
                    else
                    {
                        if (sign(a) != sign(b))
                            x.push_back(ceil);
                        else
                            x.push_back(-floor);
                    }
                }
            }
        }
        else // type == 2
        {
            ll c;
            cin >> c;
            q.push_back({2, {c, 0}});
            x.push_back(c);
        }
    }

    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());

    int constant_term_sign = 1;
    unordered_set<ll> sol;
    FenwickTree cnt(x.size());
    for (int i = 0; i < Q; ++i)
    {
        int type = q[i].first;

        if (type == 1)
        {
            ll a = q[i].second.first;
            ll b = q[i].second.second;

            if (a == 0)
            {
                constant_term_sign *= sign(b);
                continue;
            }

            if (b % a == 0)
            {
                sol.insert(-(b / a));

                if (a > 0)
                    cnt.add(1, get_idx(-(b / a) - 1, x) + 1, 1);
                else
                    cnt.add(get_idx(-(b / a) + 1, x) + 1, x.size(), 1);
            }
            else
            {
                ll floor = abs(b) / abs(a);
                ll ceil = (abs(b) + abs(a) - 1) / abs(a);

                if (a > 0)
                {
                    if (sign(a) != sign(b))
                        cnt.add(1, get_idx(floor, x) + 1, 1);
                    else
                        cnt.add(1, get_idx(-ceil, x) + 1, 1);
                }
                else
                {
                    if (sign(a) != sign(b))
                        cnt.add(get_idx(ceil, x) + 1, x.size(), 1);
                    else
                        cnt.add(get_idx(-floor, x) + 1, x.size(), 1);
                }
            }
        }
        else
        {
            ll c = q[i].second.first;
            if (sol.find(c) != sol.end())
            {
                cout << 0 << '\n';
                continue;
            }

            int c_sign = constant_term_sign * ((cnt.get_sum(get_idx(c + 1, x)) % 2 == 0) ? 1 : -1);
            if (c_sign > 0)
                cout << '+' << '\n';
            else if (c_sign == 0)
                cout << 0 << '\n';
            else // c_sign < 0
                cout << '-' << '\n';
        }
    }
}