#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int MAX_N = 500000;
const int MAX_NUM = 1000000;

int N;
int idx[MAX_NUM + 1];
int arr[MAX_N + 1];
ll tree[MAX_N + 1];

ll sum(int i)
{
    ll ret = 0;
    while (i > 0)
    {
        ret += tree[i];
        i -= (i & -i);
    }

    return ret;
}

void add(int i, ll num)
{
    while (i <= N)
    {
        tree[i] += num;
        i += (i & -i);
    }
}

ll inversionCounting()
{
    ll ret = 0;

    for (int i = N; i > 0; i--)
    {
        int tree_idx = idx[arr[i]];
        ret += sum(tree_idx - 1);
        add(tree_idx, 1);
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        int num;
        cin >> num;
        idx[num] = i;
    }

    for (size_t i = 1; i <= N; i++)
        cin >> arr[i];

    cout << inversionCounting() << '\n';
}

// Inversion Counting with fenwick tree