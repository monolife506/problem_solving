#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 0; tc < T; ++tc)
    {
        string str;
        cin >> str;

        stack<int> l, r;
        for (char c : str)
        {
            if (c == '<')
            {
                if (!l.empty())
                {
                    r.push(l.top());
                    l.pop();
                }
            }
            else if (c == '>')
            {
                if (!r.empty())
                {
                    l.push(r.top());
                    r.pop();
                }
            }
            else if (c == '-')
            {
                if (!l.empty())
                    l.pop();
            }
            else
            {
                l.push(c);
            }
        }

        vector<char> ans;
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

        for (int i = 0; i < ans.size(); ++i)
            cout << ans[i];

        cout << '\n';
    }
}