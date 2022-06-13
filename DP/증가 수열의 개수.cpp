#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

struct FenwickTree
{
    size_t sz;
    vector<ll> tree;

    FenwickTree(size_t sz) : sz(sz) { tree.resize(sz + 1, 0); }

    void add(int i, ll val)
    {
        while (i <= sz)
        {
            tree[i] += val;
            tree[i] %= MOD;
            i += (i & -i);
        }
    }

    ll get_sum(int i)
    {
        ll ret = 0;
        while (i > 0)
        {
            ret += tree[i];
            ret %= MOD;
            i -= (i & -i);
        }
        return ret;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> A[i];

    vector<FenwickTree> cache(K + 1, FenwickTree(N));
    for (int i = 1; i <= N; ++i)
    {
        cache[1].add(A[i], 1);
        for (int k = 2; k <= K; ++k)
            cache[k].add(A[i], cache[k - 1].get_sum(A[i] - 1));
    }

    cout << cache[K].get_sum(N) << '\n';
}