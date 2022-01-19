#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool visited[501][501][501];

bool bfs(vector<int> start)
{
    queue<vector<int>> q;
    sort(start.begin(), start.end());
    q.push(start);
    visited[start[0]][start[1]][start[2]] = true;

    while (!q.empty())
    {
        vector<int> cur = q.front(), nxt;
        q.pop();

        if (cur[0] == cur[1] && cur[1] == cur[2])
            return true;

        if (cur[0] != cur[1])
        {
            nxt = {cur[0] * 2, cur[1] - cur[0], cur[2]};
            sort(nxt.begin(), nxt.end());
            if (!visited[nxt[0]][nxt[1]][nxt[2]])
            {
                q.push(nxt);
                visited[nxt[0]][nxt[1]][nxt[2]] = true;
            }
        }
        if (cur[0] != cur[2])
        {
            nxt = {cur[0] * 2, cur[1], cur[2] - cur[0]};
            sort(nxt.begin(), nxt.end());
            if (!visited[nxt[0]][nxt[1]][nxt[2]])
            {
                q.push(nxt);
                visited[nxt[0]][nxt[1]][nxt[2]] = true;
            }
        }
        if (cur[1] != cur[2])
        {
            nxt = {cur[0], cur[1] * 2, cur[2] - cur[1]};
            sort(nxt.begin(), nxt.end());
            if (!visited[nxt[0]][nxt[1]][nxt[2]])
            {
                q.push(nxt);
                visited[nxt[0]][nxt[1]][nxt[2]] = true;
            }
        }
    }

    return false;
}

int main()
{
    vector<int> start(3);
    cin >> start[0] >> start[1] >> start[2];
    cout << bfs(start) << '\n';
}
