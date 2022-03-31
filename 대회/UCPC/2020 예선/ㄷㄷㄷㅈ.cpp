#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;

vector<int> tree[300001];
ll depth[300001];
ll dCnt = 0, gCnt = 0;

void traverse(int cur)
{
    ll oneChild = 0;
    ll twoChild = 0;

    for (int &node : tree[cur])
    {
        if (depth[node] == -1)
        {
            depth[node] = depth[cur] + 1;
            traverse(node);

            oneChild++;
            if (tree[node].size() >= 2)
                twoChild += tree[node].size() - 1;
        }
    }

    if (depth[cur] >= 3)
        dCnt++; // ㄷ트리 (1)
    if (twoChild >= 1)
        dCnt += ((oneChild - 1) * twoChild); // ㄷ트리 (2)

    if (tree[cur].size() >= 3) // ㅈ트리
    {
        ll N = tree[cur].size();
        gCnt += N * (N - 1) * (N - 2) / 6;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(depth, -1, sizeof(depth));

    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }

    depth[1] = 0;
    traverse(1);

    if (dCnt > gCnt * 3)
        cout << "D";
    else if (dCnt < gCnt * 3)
        cout << "G";
    else
        cout << "DUDUDUNGA";
}