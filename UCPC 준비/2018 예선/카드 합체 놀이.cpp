// 15903번: 카드 합체 놀이

#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    int N, M;
    ll num, total = 0;
    cin >> N >> M;
    for (size_t i = 0; i < N; i++)
    {
        cin >> num;
        total += num;
        pq.push(num);
    }

    for (size_t i = 0; i < M; i++)
    {
        ll num1 = pq.top();
        pq.pop();
        ll num2 = pq.top();
        pq.pop();
        total -= (num1 + num2);

        pq.push(num1 + num2);
        pq.push(num1 + num2);
        total += 2 * (num1 + num2);
    }

    cout << total;
}