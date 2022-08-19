#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int A[100001], root[100001];

int find(int n)
{
    if (root[n] < 0)
        return n;
    else
        return root[n] = find(root[n]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        root[a] += root[b];
        root[b] = a;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(root, -1, sizeof(root));

    int N;
    cin >> N;

    vector<int> nodes(N);
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
        nodes[i - 1] = i;
    }

    vector<P> edges(N - 1);
    for (int i = 0; i < N - 1; ++i)
        cin >> edges[i].first >> edges[i].second;

    sort(nodes.begin(), nodes.end(), [](int &lhs, int &rhs) -> bool
         { return A[lhs] < A[rhs]; });
    sort(edges.begin(), edges.end(), [](P &lhs, P &rhs) -> bool
         { return min(A[lhs.first], A[lhs.second]) < min(A[rhs.first], A[rhs.second]); });

    ll ans = 0;
    int j = N - 2; // edge idx
    for (int i = N - 1; i >= 0; --i)
    {
        while (j >= 0 && min(A[edges[j].first], A[edges[j].second]) >= A[nodes[i]])
        {
            merge(edges[j].first, edges[j].second);
            --j;
        }

        ans = max(ans, 1LL * abs(root[find(nodes[i])]) * A[nodes[i]]);
    }

    cout << ans << '\n';
}