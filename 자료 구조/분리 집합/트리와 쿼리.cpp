#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;

int N, Q, p[250001], root[250001];
vector<int> tree[250001];

void dfs(int cur, int parent)
{
    p[cur] = parent;
    for (int nxt : tree[cur])
    {
        if (nxt == parent)
            continue;

        dfs(nxt, cur);
    }
}

int find(int n, unordered_map<int, int> &root)
{
    if (root[n] < 0)
        return n;
    else
        return root[n] = find(root[n], root);
}

void merge(int a, int b, unordered_map<int, int> &root)
{
    a = find(a, root);
    b = find(b, root);
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

    cin >> N;
    for (int i = 0; i < N - 1; ++i)
    {
        int A, B;
        cin >> A >> B;
        tree[A].push_back(B);
        tree[B].push_back(A);
    }

    dfs(1, -1);

    cin >> Q;
    for (int q = 0; q < Q; ++q)
    {
        int K;
        cin >> K;

        unordered_set<int> s;
        unordered_map<int, int> root;
        for (int i = 0; i < K; ++i)
        {
            int num;
            cin >> num;
            s.insert(num);
            root[num] = -1;
        }

        ll ans = 0;
        for (int num : s)
        {
            if (s.find(p[num]) != s.end())
                merge(num, p[num], root);
        }
        for (int num : s)
        {
            if (num == find(num, root))
                ans += 1LL * abs(root[num]) * (abs(root[num]) - 1) / 2;
        }

        cout << ans << '\n';
    }
}

/*

N개의 node를 가진 Tree: 연결쌍의 개수는 N * (N - 1) / 2
트리의 부분집합 -> 트리

*/