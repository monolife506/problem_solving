#include <bits/stdc++.h>
#define endl '\n';
using namespace std;

typedef pair<int, int> pii;

map<string, vector<string>> graph;
set<string> visited;

void dfs(const string &cur)
{
    visited.insert(cur);
    for (auto &nxt : graph[cur])
    {
        if (visited.find(nxt) != visited.end())
            continue;

        dfs(nxt);
    }
}

void sol()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string a, is, b;
        cin >> a >> is >> b;

        graph[a].push_back(b);
    }

    dfs("Baba");

    if (visited.size() == 1)
    {
        return;
    }
    else
    {
        visited.erase("Baba");
        for (auto str : visited)
            cout << str << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sol();
}