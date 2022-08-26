#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int N;
char c[500001];
vector<int> tree[500001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> c;
    for (int i = 0; i < N - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        tree[u - 1].push_back(v - 1);
        tree[v - 1].push_back(u - 1);
    }

    vector<P> node, edge;
    node.push_back({0, -1});

    string ans;
    ans.push_back(c[0]);

    while (true)
    {
        char max_c = -1;

        edge.clear();
        for (P p : node)
        {
            int cur = p.first;
            int parent = p.second;
            for (int nxt : tree[cur])
            {
                if (nxt == parent)
                    continue;

                edge.push_back({cur, nxt});
                max_c = max(max_c, c[nxt]);
            }
        }

        node.clear();
        for (P p : edge)
        {
            int cur = p.first;
            int nxt = p.second;
            if (c[nxt] == max_c)
                node.push_back({nxt, cur});
        }

        if (max_c == -1)
            break;

        ans.push_back(max_c);
    }

    cout << ans << '\n';
}