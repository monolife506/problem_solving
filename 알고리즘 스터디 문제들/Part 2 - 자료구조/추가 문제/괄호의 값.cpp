#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string str;
    cin >> str;

    int tmp = 0;      // 현재 괄호 내부에서의 괄호값
    bool flag = true; // 제대로 된 문자열인지 확인하는 flag

    // bool: 이 데이터가 문자인지 아닌지 확인
    // int: 문자의 아스키 코드나 괄호값
    stack<pair<bool, int>> S;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '[' || str[i] == '(')
        {
            if (str[i] == '[')
                S.push({true, '['});
            else // str[i] == '('
                S.push({true, '('});
        }
        else // str[i] == ']' or ')'
        {
            tmp = 0;
            while (!S.empty())
            {
                if (!S.top().first)
                {
                    tmp += S.top().second;
                    S.pop();
                }
                else
                    break;
            }
            if (S.empty())
            {
                flag = false;
                break;
            }

            if (str[i] == ']' && S.top().second == '[')
            {
                S.pop();
                (tmp == 0) ? S.push({false, 3})
                           : S.push({false, tmp * 3});
            }
            else if (str[i] == ')' && S.top().second == '(')
            {
                S.pop();
                (tmp == 0) ? S.push({false, 2})
                           : S.push({false, tmp * 2});
            }
            else
            {
                flag = false;
                break;
            }
        }
    }

    int sum = 0; // 합계

    // 올바른 문자열인 경우 괄호값들만 남을 것이다.
    // 이때의 합을 구하면 된다.
    while (!S.empty() && flag)
    {
        if (S.top().first)
        {
            flag = false;
            break;
        }

        sum += S.top().second;
        S.pop();
    }

    cout << ((flag) ? sum : 0);
}