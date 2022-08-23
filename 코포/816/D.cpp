#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Query
{
    int i, j, x;
    Query(int i, int j, int x) : i(i), j(j), x(x) {}

    bool operator<(Query &rhs) const
    {
        if (i != rhs.i)
            return i < rhs.i;
        else
            return j < rhs.j;
    }
};

int arr[100001], flag[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i)
        flag[i] = (1 << 30) - 1;

    vector<Query> queries;
    for (int query = 0; query < q; ++query)
    {
        int i, j, x;
        cin >> i >> j >> x;

        if (i > j)
            swap(i, j);

        flag[i] &= x;
        flag[j] &= x;
        queries.push_back(Query(i, j, x));
    }

    sort(queries.begin(), queries.end());
    for (int i = 0; i < 30; ++i)
    {
        for (int j = queries.size() - 1; j >= 0; --j)
        {
            if ((queries[j].x & (1 << i)) == 0)
                continue;
            if (((arr[queries[j].i] | arr[queries[j].j]) & (1 << i)) == 0)
            {
                if ((flag[queries[j].j] & (1 << i)) == 0)
                    arr[queries[j].i] |= (1 << i);
                else
                    arr[queries[j].j] |= (1 << i);
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << arr[i] << " ";

    cout << '\n';
}

/*

010 001 000 -> 2 1 0

3 2
2 3 1
1 2 3


*/