#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_V = 10000;

int V, E;
vector<int> graph[MAX_V + 1];

int counter = 0;
int discovered[MAX_V + 1]; // dfs 스패닝 트리의 순회 순서
bool isCutVertex[MAX_V + 1];

int getCutVertex(int cur, bool is_root)
{
    discovered[cur] = counter++;
    int ret = discovered[cur];
    int child_cnt = 0;

    for (int &next : graph[cur])
    {
        if (discovered[next] == -1) // 트리 간선
        {
            int subtree = getCutVertex(next, false);
            if (!is_root && subtree >= discovered[cur])
                isCutVertex[cur] = true;

            ret = min(ret, subtree);
            child_cnt++;
        }
        else
        {
            ret = min(ret, discovered[next]);
        }
    }

    if (is_root)
        isCutVertex[cur] = (child_cnt >= 2);

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(discovered, -1, sizeof(discovered));

    cin >> V >> E;
    for (size_t i = 0; i < E; i++)
    {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    vector<int> ans;
    for (size_t i = 1; i <= V; i++)
    {
        if (discovered[i] == -1)
            getCutVertex(i, true);
        if (isCutVertex[i])
            ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for (int &num : ans)
        cout << num << " ";
}
