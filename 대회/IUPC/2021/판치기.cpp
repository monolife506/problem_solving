#include <iostream>
#include <queue>
#include <string>
using namespace std;

const int MAX = 3000;
typedef pair<int, int> P;

int N, K;
bool visited[MAX + 1];

int bfs(int start)
{
    queue<P> q;
    q.push(P(start, 0));
    visited[start] = true;

    while (!q.empty())
    {
        int H = q.front().first;    // 현재 H의 개수
        int cnt = q.front().second; // 뒤집은 횟수
        q.pop();

        if (H == 0)
            return cnt;

        for (int i = max(K - (N - H), 0); i <= min(H, K); i++) // 뒤집을 H의 개수
        {
            int next = (H - i) + (K - i);

            if (!visited[next])
            {
                q.push(P(next, cnt + 1));
                visited[next] = true;
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string S;
    cin >> N >> K >> S;

    int cnt = 0; // S에서 H의 개수
    for (const char &c : S)
    {
        if (c == 'H')
            cnt++;
    }

    cout << bfs(cnt) << '\n';
}

// N = 10, H = 5, K = 3 (0 ~ 3)
// N = 10, H = 5, K = 5 (0 ~ 5)
// N = 10, H = 5, K = 7 (2 ~ 5)
// N = 10, H = 5, K = 3 (0 ~ 3)
// N = 10, H = 9, K = 10 (9)
// N = 10, H = 7, K = 4 (1 ~ 4)