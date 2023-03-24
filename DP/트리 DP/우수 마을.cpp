#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int N, population[10001], cache[2][10001];
vector<int> tree[10001];

void traverse(int cur, int parent)
{
    cache[0][cur] = 0;
    cache[1][cur] = population[cur];

    for (int &nxt : tree[cur])
    {
        if (nxt == parent)
            continue;

        traverse(nxt, cur);
        cache[0][cur] += max(cache[0][nxt], cache[1][nxt]);
        cache[1][cur] += cache[0][nxt];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(cache, -1, sizeof(cache));

    cin >> N;
    for (size_t i = 1; i <= N; i++)
        cin >> population[i];
    for (size_t i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    traverse(1, -1);
    cout << max(cache[0][1], cache[1][1]) << '\n';
}