#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    priority_queue<P, vector<P>, greater<P>> pq;
    for (size_t i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;

        if (A <= B)
            continue;

        pq.push(P(B, A));
    }

    ll ans = M;
    while (!pq.empty()) {
        int left = pq.top().first;
        int right = pq.top().second;
        pq.pop();

        while (!pq.empty() && pq.top().first <= right) {
            right = max(right, pq.top().second);
            pq.pop();
        }

        ans += (right - left) * 2;
    }

    cout << ans;
}