#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int MAX_N = 10000;

int N;
vector<int> graph[MAX_N * 2 + 1];

int cnt, scc_cnt;
int visited[MAX_N * 2 + 1];   // dfs 트리에서의 탐색 순서
bool finished[MAX_N * 2 + 1]; // SCC 추출이 완전히 종료되었는가
stack<int> S;                 // SCC 추출에 사용되는 stack
int scc[MAX_N * 2 + 1];

int notX(int x)
{
    return (x > MAX_N) ? x - MAX_N : x + MAX_N;
}

int dfs(int cur)
{
    visited[cur] = ++cnt;
    S.push(cur);

    int ret = visited[cur];
    for (int next : graph[cur])
    {
        if (visited[next] == 0)
            ret = min(ret, dfs(next));
        else if (!finished[next])
            ret = min(ret, visited[next]);
    }

    // SCC 추출
    if (ret == visited[cur])
    {
        ++scc_cnt;
        while (true)
        {
            int top = S.top();
            S.pop();

            scc[top] = scc_cnt;
            finished[top] = true;
            if (top == cur)
                break;
        }
    }

    return ret;
}

bool solve2SAT()
{
    for (size_t i = 1; i <= N; i++)
    {
        int not_i = notX(i);
        if (visited[i] == 0)
            dfs(i);
        if (visited[not_i] == 0)
            dfs(not_i);

        if (scc[i] == scc[not_i])
            return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin >> N >> M;
    for (size_t k = 0; k < M; k++)
    {
        int i, j;
        cin >> i >> j;

        i = (i > 0) ? i : notX(-i);
        j = (j > 0) ? j : notX(-j);
        graph[notX(i)].push_back(j);
        graph[notX(j)].push_back(i);
    }

    cout << solve2SAT() << '\n';
}