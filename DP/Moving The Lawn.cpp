#include <deque>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

ll psum[100001], cache[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
    {
        ll E;
        cin >> E;
        psum[i] = psum[i - 1] + E;
    }

    deque<P> dq;
    for (int i = 0; i <= K; ++i)
    {
        cache[i] = psum[i];
        while (!dq.empty() && dq.back().first < cache[i] - psum[i + 1])
            dq.pop_back();
        dq.push_back({cache[i] - psum[i + 1], i});
    }
    for (int i = K + 1; i < N; ++i)
    {
        cache[i] = dq.front().first + psum[i];
        while (!dq.empty() && dq.back().first < cache[i] - psum[i + 1])
            dq.pop_back();
        dq.push_back({cache[i] - psum[i + 1], i});
        while (dq.front().second < i - K)
            dq.pop_front();
    }

    cache[N] = dq.front().first + psum[N];
    cout << cache[N] << '\n';
}