#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

int D[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> D[i];

    ll ans = 0;
    stack<int> s;
    for (int i = 1; i <= N; ++i)
    {
        while (!s.empty() && D[s.top()] > D[i])
        {
            int j = s.top();
            s.pop();

            ans = max(ans, 1LL * (!s.empty() ? i - s.top() - 1 : i - 1) * D[j]);
        }

        s.push(i);
    }

    while (!s.empty())
    {
        int j = s.top();
        s.pop();

        ans = max(ans, 1LL * (!s.empty() ? N - s.top() : N) * D[j]);
    }

    cout << ans << '\n';
}