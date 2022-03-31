#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

struct FenwickTree
{
    size_t n;
    ll *tree;

    FenwickTree(size_t n) : n(n)
    {
        tree = new ll[n + 1];
        memset(tree, 0, sizeof(tree));
    }

    ll get_val(int i)
    {
        ll ret = 0;
        while (i > 0)
        {
            ret += tree[i];
            i -= (i & -i);
        }

        return ret;
    }

    void update(int i, ll val)
    {
        while (i <= n)
        {
            tree[i] += val;
            i += (i & -i);
        }
    }
};

ll A[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N, Q;
    cin >> N;
    for (size_t i = 1; i <= N; ++i)
        cin >> A[i];

    cin >> Q;
    FenwickTree diff(N), cnt(N);
    for (size_t i = 0; i < Q; ++i)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            int L, R;
            cin >> L >> R;

            diff.update(L, L);
            cnt.update(L, 1);
            if (R != N)
            {
                diff.update(R + 1, -L);
                cnt.update(R + 1, -1);
            }
        }
        else
        {
            int X;
            cin >> X;
            cout << A[X] + cnt.get_val(X) * (X + 1) - diff.get_val(X) << '\n';
        }
    }
}