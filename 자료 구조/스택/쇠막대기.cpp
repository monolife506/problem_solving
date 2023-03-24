#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;

    int cnt = 0;

    stack<char> s;
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == '(')
        {
            if (str[i + 1] == ')')
            {
                cnt += s.size();
                ++i;
            }
            else
            {
                s.push('(');
            }
        }
        else
        {
            s.pop();
            ++cnt;
        }
    }

    cout << cnt << '\n';
}

/*

(()) 2
(())(()) 4
(()()) 3
(((()())(())())) 15

*/