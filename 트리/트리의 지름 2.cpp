#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

vector<P> tree[10001];
int max_len[10001]; // max_len[i]: i번 노트를 루트로 하는 서브트리의 최대 지름

int dfs(int cur)
{
    if (tree[cur].empty())
        return 0;

    int first = 0, second = 0;
    for (P &p : tree[cur])
    {
        int len = dfs(p.first) + p.second;
        if (len > first)
        {
            second = first;
            first = len;
        }
        else if (len > second)
        {
            second = len;
        }
    }

    max_len[cur] = first + second;
    return first;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int parent, child, w;
        cin >> parent >> child >> w;
        tree[parent].push_back({child, w});
    }

    dfs(1);

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, max_len[i]);

    cout << ans << '\n';
}