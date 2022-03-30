#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
typedef pair<int, int> P;

struct DisjointSet
{
    int *root;

    DisjointSet(size_t n)
    {
        root = new int[n];
        memset(root, -1, sizeof(int) * n);
    }

    ~DisjointSet() { delete[] root; }

    int find(int cur)
    {
        if (root[cur] < 0)
            return cur;
        return root[cur] = find(root[cur]);
    }

    bool merge(int a, int b)
    {
        a = find(a);
        b = find(b);

        if (a == b)
            return false; // no merge

        root[b] = a;
        return true; // merged
    }
};

int parent[200001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N, Q;
    cin >> N >> Q;
    for (size_t i = 2; i <= N; ++i)
        cin >> parent[i];

    stack<P> query;
    stack<bool> ans;
    DisjointSet node_set(N + 1);

    for (size_t i = 0; i < (N - 1) + Q; ++i)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            int b;
            cin >> b;
            query.push({b, 0});
        }
        else // x == 1
        {
            int c, d;
            cin >> c >> d;
            query.push({c, d});
        }
    }

    while (!query.empty())
    {
        P top = query.top();
        query.pop();

        if (top.second == 0)
            node_set.merge(top.first, parent[top.first]);
        else
            ans.push(node_set.find(top.first) == node_set.find(top.second));
    }

    while (!ans.empty())
    {
        cout << (ans.top() ? "YES" : "NO") << '\n';
        ans.pop();
    }
}