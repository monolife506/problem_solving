#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;

P p[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> p[i].first >> p[i].second;

    sort(p, p + N);
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(p[0].second);
    for (int i = 1; i < N; ++i)
    {
        if (pq.top() <= p[i].first)
        {
            pq.pop();
            pq.push(p[i].second);
        }
        else
        {
            pq.push(p[i].second);
        }
    }

    cout << pq.size() << '\n';
}
