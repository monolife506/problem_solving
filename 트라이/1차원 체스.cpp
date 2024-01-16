#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll ans[10001];

struct Trie
{
    map<int, Trie *> child;
    int leaf_cnt = 0, subtree_leaf_cnt = 0;

    ~Trie()
    {
        for (pair<const int, Trie *> &p : child)
        {
            if (p.second != nullptr)
                delete p.second;
        }
    }

    void insert(const vector<int> &v, int idx = 0)
    {
        if (idx == v.size())
        {
            leaf_cnt++;
            subtree_leaf_cnt++;
            return;
        }

        int next = v[idx];
        if (child[next] == nullptr)
            child[next] = new Trie();

        child[next]->insert(v, idx + 1);
        subtree_leaf_cnt++;
    }

    void dfs(int cur = 0)
    {
        if (child.empty())
            return;

        ll child_leaf_sum = subtree_leaf_cnt - leaf_cnt, branch_cnt = 0;
        for (auto [num, nxt] : child)
        {
            nxt->dfs(num);
            branch_cnt += (child_leaf_sum - nxt->subtree_leaf_cnt) * nxt->subtree_leaf_cnt;
        }

        branch_cnt /= 2;
        ans[cur] += branch_cnt;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;

    Trie trie;
    for (int i = 0; i < n; ++i)
    {
        int s;
        cin >> s;

        vector<int> a(s);
        for (int j = 0; j < s; ++j)
            cin >> a[j];

        trie.insert(a);
    }

    trie.dfs();
    for (int i = 0; i < q; ++i)
    {
        int qi;
        cin >> qi;
        cout << ans[qi] << '\n';
    }
}

/*

2, 3, 4

1 2

1 * 2
2 * 1

1 * 1
1 * 1

2 (3 + 4)

*/