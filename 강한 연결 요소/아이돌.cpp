#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int MAX_N = 1000;

int N;
vector<int> graph[2 * MAX_N + 1];

int cnt, scc_cnt;
int scc[MAX_N * 2 + 1];
int visited[MAX_N * 2 + 1];
bool finished[MAX_N * 2 + 1];

inline int notX(int x)
{
    return (x > MAX_N) ? x - MAX_N : x + MAX_N;
}

int dfs(int cur, stack<int> &S)
{
    visited[cur] = ++cnt;
    S.push(cur);

    int ret = visited[cur];
    for (int next : graph[cur])
    {
        if (visited[next] == 0)
            ret = min(ret, dfs(next, S));
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
    cnt = scc_cnt = 0;
    memset(scc, 0, sizeof(scc));
    memset(visited, 0, sizeof(visited));
    memset(finished, 0, sizeof(finished));
    stack<int> S;

    for (size_t i = 1; i <= N; i++)
    {
        int not_i = notX(i);
        if (visited[i] == 0)
            dfs(i, S);
        if (visited[not_i] == 0)
            dfs(not_i, S);

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

    while (cin >> N)
    {
        // 그래프 초기화
        for (size_t i = 1; i <= MAX_N * 2; i++)
            graph[i].clear();

        int M;
        cin >> M;
        for (size_t i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;
            a = (a > 0) ? a : notX(-a);
            b = (b > 0) ? b : notX(-b);
            graph[notX(a)].push_back(b);
            graph[notX(b)].push_back(a);
        }

        // 상근이가 합격해야 함
        graph[notX(1)].push_back(1);

        cout << (solve2SAT() ? "yes" : "no") << '\n';
    }
}