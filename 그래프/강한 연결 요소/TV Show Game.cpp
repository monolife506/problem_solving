#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

size_t N, M;
vector<int> graph[20001];

int cnt, scc_cnt, visited[20001], scc[20001], ans[20001];

inline int not_x(int n) { return (n > 10000) ? n - 10000 : n + 10000; }

int dfs(int cur)
{
    static stack<int> s;
    visited[cur] = ++cnt;
    s.push(cur);

    int ret = visited[cur];
    for (int nxt : graph[cur])
    {
        if (visited[nxt] == 0)
            ret = min(ret, dfs(nxt));
        else if (scc[nxt] == 0)
            ret = min(ret, visited[nxt]);
    }

    if (visited[cur] == ret)
    {
        ++scc_cnt;
        while (true)
        {
            int top = s.top();
            s.pop();

            scc[top] = scc_cnt;
            if (top == cur)
                break;
        }
    }

    return ret;
}

bool solve_2sat()
{
    for (int i = 1; i <= N; ++i)
    {
        int not_i = not_x(i);
        if (visited[i] == 0)
            dfs(i);
        if (visited[not_i] == 0)
            dfs(not_i);

        if (scc[i] == scc[not_i])
            return false;
    }

    vector<pair<int, int>> v;
    memset(ans, -1, sizeof(ans));
    for (int i = 1; i <= N; ++i)
    {
        int not_i = not_x(i);
        v.push_back(make_pair(scc[i], i));
        v.push_back(make_pair(scc[not_i], not_i));
    }

    sort(v.begin(), v.end());
    for (int i = v.size() - 1; i >= 0; --i)
    {
        int idx = v[i].second;
        int not_idx = not_x(idx);
        if (ans[idx] == -1)
        {
            ans[idx] = false;
            ans[not_idx] = true;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (size_t i = 0; i < M; ++i)
    {
        int l[3];
        for (size_t j = 0; j < 3; ++j)
        {
            char c;
            cin >> l[j] >> c;
            l[j] = (c == 'R') ? l[j] : not_x(l[j]);
        }
        for (size_t j = 0; j < 3; ++j)
        {
            graph[not_x(l[j])].push_back(l[(j + 1) % 3]);
            graph[not_x(l[j])].push_back(l[(j + 2) % 3]);
        }
    }

    if (solve_2sat())
    {
        for (size_t i = 1; i <= N; ++i)
            cout << (ans[i] == 0 ? 'B' : 'R');
    }
    else
    {
        cout << -1;
    }

    cout << '\n';
}

// R: true, B: false