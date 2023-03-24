#include <deque>
#include <iostream>
using namespace std;
typedef pair<int, int> P;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, L;
    cin >> N >> L;

    deque<P> dq; // Decreasing Monotonic Queue
    for (int idx = 0; idx < N; ++idx)
    {
        int val;
        cin >> val;

        while (!dq.empty() && dq.back().first > val)
            dq.pop_back();

        dq.push_back({val, idx});
        while (dq.front().second <= idx - L)
            dq.pop_front();

        cout << dq.front().first << " ";
    }

    cout << '\n';
}