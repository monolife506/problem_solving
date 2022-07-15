#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int N, a[500001], in[500001], out[500001];
vector<int> tree[500001];

void dfs(int cur, int depth, vector<P> &v)
{
    v.push_back({a[cur], depth});
    in[cur] = v.size() - 1;
    for (int nxt : tree[cur])
    {
        dfs(nxt, depth + 1, v);
        v.push_back({a[cur], depth});
    }

    out[cur] = v.size() - 1;
}

void manacher(const vector<P> &v, vector<int> &p)
{
    p.resize(v.size());

    int c = -1, r = -1;
    for (int i = 0; i < p.size(); ++i)
    {
        if (r < i)
        {
            p[i] = 0;
            while (i - p[i] - 1 >= 0 && i + p[i] + 1 < v.size() && v[i - p[i] - 1] == v[i + p[i] + 1])
                ++p[i];

            c = i;
            r = i + p[i];
        }
        else // r >= i
        {
            p[i] = min(r - i, p[c * 2 - i]);
            if (r - i == p[c * 2 - i])
            {
                while (i - p[i] - 1 >= 0 && i + p[i] + 1 < v.size() && v[i - p[i] - 1] == v[i + p[i] + 1])
                    ++p[i];

                c = i;
                r = i + p[i];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> a[i];
    for (int i = 0; i < N - 1; ++i)
    {
        int parent, child;
        cin >> parent >> child;
        tree[parent].push_back(child);
    }
    for (int i = 1; i <= N; ++i)
        sort(tree[i].begin(), tree[i].end());

    vector<P> v;
    vector<int> p;
    dfs(1, 0, v);
    manacher(v, p);

    vector<int> ans;
    for (int i = 1; i <= N; ++i)
    {
        if (p[(in[i] + out[i]) / 2] >= (out[i] - in[i] + 1) / 2)
            ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for (int num : ans)
        cout << num << " ";

    cout << '\n';
}