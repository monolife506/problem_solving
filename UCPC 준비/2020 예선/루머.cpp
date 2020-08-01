#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

int N, M, num;
vector<int> graph[200001];

queue<int> Q;
int rumorTime[200001];
int rumorCnt[200001];

void bfs()
{
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        for (int node : graph[cur])
        {
            if (rumorTime[node] == -1)
            {
                if (++rumorCnt[node] >= ceil((double)graph[node].size() / 2))
                {
                    Q.push(node);
                    rumorTime[node] = rumorTime[cur] + 1;
                }
            }
        }
    }
}

int main()
{
    memset(rumorTime, -1, sizeof(rumorTime));
    memset(rumorCnt, 0, sizeof(rumorCnt));

    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> num;
        while (num != 0)
        {
            if (num != 0)
                graph[i].push_back(num);
            cin >> num;
        }
    }

    cin >> M;
    for (size_t i = 0; i < M; i++)
    {
        cin >> num;
        Q.push(num);
        rumorTime[num] = 0;
    }

    bfs();
    for (size_t i = 1; i <= N; i++)
        cout << rumorTime[i] << " ";
}