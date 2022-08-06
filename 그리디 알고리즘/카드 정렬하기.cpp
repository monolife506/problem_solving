#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        pq.push(num);
    }

    int ans = 0;
    while (pq.size() >= 2)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        ans += first + second;
        pq.push(first + second);
    }

    cout << ans << '\n';
}

/*

10 20 -> 30
30 30 -> 60
60 40 -> 100

190

2
30 50

*/