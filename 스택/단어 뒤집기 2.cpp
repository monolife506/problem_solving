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
    getline(cin, S);

    stack<char> s;
    bool in_tag = false;
    for (int i = 0; i < S.length(); ++i)
    {
        if (S[i] == '<')
        {
            in_tag = true;
            while (!s.empty())
            {
                cout << s.top();
                s.pop();
            }
            cout << '<';
        }
        else if (S[i] == '>')
        {
            in_tag = false;
            cout << '>';
        }
        else if (S[i] == ' ' && !in_tag)
        {
            while (!s.empty())
            {
                cout << s.top();
                s.pop();
            }
            cout << ' ';
        }
        else if (!in_tag)
        {
            s.push(S[i]);
        }
        else
        {
            cout << S[i];
        }
    }

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }

    cout << '\n';
}