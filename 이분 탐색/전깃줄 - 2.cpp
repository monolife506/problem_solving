#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int, int> P;

bool used[500001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<P> connects(N);
    vector<int> seq;
    vector<int> trace;

    for (P &p : connects)
        cin >> p.first >> p.second;

    sort(connects.begin(), connects.end());
    for (P &p : connects)
    {
        if (seq.empty() || seq.back() < p.second)
        {
            seq.push_back(p.second);
            trace.push_back(seq.size() - 1);
        }
        else
        {
            auto it = lower_bound(seq.begin(), seq.end(), p.second);
            trace.push_back((int)(it - seq.begin()));
            *it = p.second;
        }
    }

    int cur = seq.size() - 1;
    for (int i = trace.size() - 1; i >= 0; i--)
    {
        if (trace[i] == cur)
        {
            used[i] = true;
            cur--;
        }
    }

    cout << N - seq.size() << '\n';
    for (int i = 0; i < connects.size(); i++)
    {
        if (!used[i])
            cout << connects[i].first << '\n';
    }
}

// 8 2 9 1 4 6 7 10
// LIS + LIS에 포함되지 않는 수의 번호 출력