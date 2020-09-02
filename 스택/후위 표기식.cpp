// 1918번: 후위 표기식
// 스택을 이용한 후위 표기식 구현

#include <iostream>
#include <string>
#include <stack>
using namespace std;
typedef pair<char, int> P;

int main()
{
    string infix;
    stack<P> S;
    cin >> infix;

    int priority = 0;
    for (char &chr : infix)
    {
        if (chr == '(')
        {
            priority += 2;
            continue;
        }
        else if (chr == ')')
        {
            priority -= 2;
            continue;
        }

        if (chr >= 'A' && chr <= 'Z')
            cout << chr;
        else
        {
            if (chr == '*' || chr == '/')
                priority++;

            if (S.empty())
                S.push(P(chr, priority));
            else
            {
                while (!S.empty() && priority <= S.top().second)
                {
                    cout << S.top().first;
                    S.pop();
                }

                S.push(P(chr, priority));
            }

            if (chr == '*' || chr == '/')
                priority--;
        }
    }

    while (!S.empty())
    {
        cout << S.top().first;
        S.pop();
    }
}

// (A+(B*C))
// A (
// AB (+(
// ABC (+(*
// ABC* (+
// ABC*+

// (A+B*C)
// A (
// AB (+
// ABC (+*
// ABC+*

// ((A+(B*C))-(D/E))
// ABC ((+(*
// ABC*+DE (-(/
// ABC*+DE/-