#include <iostream>
#include <stack>
using namespace std;
const int MAX = 100000;

int histogram[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, ans = 0;
    stack<int> s;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> histogram[i];
        while (!s.empty() && histogram[s.top()] > histogram[i])
        {
            int top = s.top();
            s.pop();

            ans = max(ans, (i - (s.empty() ? 0 : s.top() + 1)) * histogram[top]);
        }

        s.push(i);
    }

    while (!s.empty())
    {
        int top = s.top();
        s.pop();

        ans = max(ans, (N - ((s.empty()) ? 0 : s.top() + 1)) * histogram[top]);
    }

    cout << ans << '\n';
}