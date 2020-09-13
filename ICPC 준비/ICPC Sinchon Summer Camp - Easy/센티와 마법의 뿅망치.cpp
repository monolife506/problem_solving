#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, centiH, T, ans = -1;
    priority_queue<int> pq;
    cin >> N >> centiH >> T;

    for (size_t i = 0; i < N; i++)
    {
        int H;
        cin >> H;
        pq.push(H);
    }

    if (centiH > pq.top())
        ans = 0;

    for (size_t i = 1; i <= T && ans == -1; i++)
    {
        int cur = pq.top();
        pq.pop();

        if (cur > 1)
            cur /= 2;

        pq.push(cur);
        if (centiH > pq.top())
            ans = i;
    }

    cout << ((ans != -1) ? "YES" : "NO") << '\n';
    cout << ((ans != -1) ? ans : pq.top());
}