#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;

int N, S, x[1000000], h[1000000];
bool visited[1000000];

void bfs()
{
    S--;

    queue<int> q;
    q.push(S);
    visited[S] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int nxt = cur + 1; nxt < N && x[nxt] <= x[cur] + h[cur]; ++nxt)
        {
            if (!visited[nxt])
            {
                visited[nxt] = true;
                q.push(nxt);
            }
        }
        for (int nxt = cur - 1; nxt >= 0 && x[nxt] >= x[cur] - h[cur]; --nxt)
        {
            if (!visited[nxt])
            {
                visited[nxt] = true;
                q.push(nxt);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> S;
    for (int i = 0; i < N; ++i)
        cin >> x[i];
    for (int i = 0; i < N; ++i)
        cin >> h[i];

    bfs();
    for (int i = 0; i < N; ++i)
    {
        if (visited[i])
            cout << i + 1 << " ";
    }
    cout << '\n';
}