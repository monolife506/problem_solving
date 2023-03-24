// 1766번: 문제집

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int indegree = 0;
    vector<int> out;
};

int N, M;
Node graph[32001];

void topological_sort(vector<int> &sorted)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (size_t i = 1; i <= N; i++)
    {
        if (graph[i].indegree == 0)
            pq.push(i);
    }
    for (size_t i = 1; i <= N; i++)
    {
        int cur = pq.top();
        pq.pop();

        sorted.push_back(cur);
        for (int &nxt : graph[cur].out)
        {
            if (--graph[nxt].indegree == 0)
                pq.push(nxt);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (size_t i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        graph[A].out.push_back(B);
        graph[B].indegree++;
    }

    vector<int> ans;
    topological_sort(ans);
    for (size_t i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}