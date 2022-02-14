#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int INF = 987654321;

vector<int> network[52];
int capacity[52][52], flow[52][52], pre[52];

int ctoi(char chr)
{
    if (chr >= 'a')
        return chr - 'a' + 26;
    else
        return chr - 'A';
}

// 에드몬드-카프 알고리즘: min(O(E * f), O(V * E^2))
int MaximumFlow(int source, int sink)
{
    int total_flow = 0;

    while (true)
    {
        queue<int> q;
        q.push(source);
        memset(pre, -1, sizeof(pre));

        while (!q.empty() && pre[sink] == -1)
        {
            int cur = q.front();
            q.pop();

            for (int nxt : network[cur])
            {
                if (capacity[cur][nxt] - flow[cur][nxt] > 0 && pre[nxt] == -1)
                {
                    q.push(nxt);
                    pre[nxt] = cur;
                }
            }
        }

        if (pre[sink] == -1)
            break;

        int amount = INF;
        for (int i = sink; i != source; i = pre[i])
            amount = min(amount, capacity[pre[i]][i] - flow[pre[i]][i]);
        for (int i = sink; i != source; i = pre[i])
        {
            flow[pre[i]][i] += amount;
            flow[i][pre[i]] -= amount;
        }

        total_flow += amount;
    }

    return total_flow;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        char a, b;
        int f;
        cin >> a >> b >> f;

        a = ctoi(a);
        b = ctoi(b);
        network[a].push_back(b);
        network[b].push_back(a);
        capacity[a][b] += f;
        capacity[b][a] += f;
    }

    cout << MaximumFlow(ctoi('A'), ctoi('Z')) << '\n';
}