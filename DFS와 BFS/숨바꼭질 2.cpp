// 12851번: 숨바꼭질 2

#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;

int N, K, cnt, minsec = -1;
bool visited[200001];

void bfs()
{
    queue<P> Q;
    Q.push(P(N, 0));
    while (!Q.empty())
    {
        int cur = Q.front().first;
        int sec = Q.front().second;
        Q.pop();

        if (minsec != -1 && sec > minsec)
            return;

        visited[cur] = true;
        if (cur == K)
        {
            if (minsec == -1)
                minsec = sec;

            cnt++;
        }

        if (cur > 0 && !visited[cur - 1])
            Q.push(P(cur - 1, sec + 1));
        if (cur < 100000 && !visited[cur + 1])
            Q.push(P(cur + 1, sec + 1));
        if (cur < 100000 && !visited[cur * 2])
            Q.push(P(cur * 2, sec + 1));
    }
}

int main()
{
    cin >> N >> K;
    bfs();
    cout << minsec << '\n'
         << cnt;
}