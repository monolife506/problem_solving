#include <iostream>
#include <queue>
using namespace std;

struct Process
{
    int i, t, p, b;
    Process(int _i, int _t, int _p, int _b) : i(_i), t(_t), p(_p), b(_b) {}
    bool operator<(const Process &rhs) const
    {
        if (p - t != rhs.p - rhs.t)
            return p - t < rhs.p - rhs.t;
        else if (b != rhs.b)
            return b > rhs.b;
        else
            return i > rhs.i;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, cur = 0;
    priority_queue<Process> pq;

    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        int t, p, b;
        cin >> t >> p >> b;

        while (!pq.empty() && cur < t)
        {
            cur += pq.top().b;
            cout << pq.top().i << " ";
            pq.pop();
        }

        if (pq.empty() && cur < t)
            cur = t;

        pq.push(Process(i, t, p, b));
    }

    while (!pq.empty())
    {
        cout << pq.top().i << " ";
        pq.pop();
    }
}