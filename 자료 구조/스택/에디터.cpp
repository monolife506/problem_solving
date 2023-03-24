#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string S;
    cin >> S;

    stack<char> l, r;
    for (const char c : S)
        l.push(c);

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        char op;
        cin >> op;

        if (op == 'L')
        {
            if (!l.empty())
            {
                r.push(l.top());
                l.pop();
            }
        }
        else if (op == 'D')
        {
            if (!r.empty())
            {
                l.push(r.top());
                r.pop();
            }
        }
        else if (op == 'B')
        {
            if (!l.empty())
                l.pop();
        }
        else // op == 'P'
        {
            char c;
            cin >> c;
            l.push(c);
        }
    }

    string ans = "";
    while (!l.empty())
    {
        ans.push_back(l.top());
        l.pop();
    }

    reverse(ans.begin(), ans.end());
    while (!r.empty())
    {
        ans.push_back(r.top());
        r.pop();
    }

    cout << ans << '\n';
}