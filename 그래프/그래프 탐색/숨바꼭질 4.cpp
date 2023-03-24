// 13913번: 숨바꼭질 4

#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

int cnt[200001];
int preN[200001];

struct P
{
    int now;
    int sec;
    int pre;

    P(int now, int sec, int pre)
    {
        this->now = now;
        this->sec = sec;
        this->pre = pre;
    }
};

void bfs(int N, int K)
{
    queue<P> Q;
    Q.push(P(N, 0, -1));

    while (!Q.empty())
    {
        int now = Q.front().now;
        int sec = Q.front().sec;
        int pre = Q.front().pre;
        Q.pop();

        if (now >= 0 && now <= 200000 && cnt[now] == -1)
        {
            cnt[now] = sec;
            if (pre != -1)
                preN[now] = pre;
            if (now == K)
                break;

            Q.push(P(now - 1, sec + 1, now));
            Q.push(P(now + 1, sec + 1, now));
            Q.push(P(now * 2, sec + 1, now));
        }
    }
}

int main()
{
    int N, K;
    cin >> N >> K;

    memset(cnt, -1, sizeof(cnt));
    memset(preN, -1, sizeof(preN));
    bfs(N, K);

    stack<int> path;
    cout << cnt[K] << '\n';
    while (K != -1)
    {
        path.push(K);
        K = preN[K];
    }
    while (!path.empty())
    {
        cout << path.top() << " ";
        path.pop();
    }
}