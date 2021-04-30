#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int moving[101];

int bfs()
{
    queue<int> Q;
    vector<int> cnt(101, -1);
    Q.push(1);
    cnt[1] = 0;

    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        if (cur == 100)
            return cnt[cur];

        for (size_t i = 1; i <= 6; i++) {
            int next = cur + i;
            if (next > 100)
                continue;
            if (moving[cur + i] != 0)
                next = moving[cur + i];

            if (cnt[next] == -1) {
                cnt[next] = cnt[cur] + 1;
                Q.push(next);
            }
        }
    }

    return -1;
}

int main()
{
    int N, M;
    cin >> N >> M;
    for (size_t i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        moving[x] = y;
    }
    for (size_t i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        moving[u] = v;
    }

    cout << bfs() << '\n';
}