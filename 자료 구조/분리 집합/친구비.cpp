#include <iostream>
#include <cstring>
using namespace std;

int cost[10001], root[10001];

int find(int cur)
{
    if (root[cur] == -1)
        return cur;
    return root[cur] = find(root[cur]);
}

void merge(int A, int B)
{
    int rootA = find(A);
    int rootB = find(B);
    if (rootA != rootB)
    {
        if (cost[rootA] >= cost[rootB])
            root[rootA] = rootB;
        else
            root[rootB] = rootA;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(root, -1, sizeof(root));

    int N, M, k, total = 0;
    cin >> N >> M >> k;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> cost[i];
    }
    for (size_t i = 0; i < M; i++)
    {
        int v, w;
        cin >> v >> w;
        merge(v, w);
    }

    for (size_t i = 1; i <= N; i++)
    {
        int curRoot = find(i);
        if (cost[curRoot] != -1)
        {
            total += cost[curRoot];
            cost[curRoot] = -1;
        }
    }

    if (total <= k)
        cout << total << '\n';
    else
        cout << "Oh no" << '\n';
}