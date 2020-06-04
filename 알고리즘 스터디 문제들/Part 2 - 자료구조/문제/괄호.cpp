#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    size_t N;
    cin >> N;

    string input;
    for (size_t i = 0; i < N; i++)
    {
        stack<char> S;
        bool flag = true;

        cin >> input;
        for (size_t j = 0; j < input.length(); j++)
        {
            if (input[j] == '(')
                S.push('(');
            else
            {
                if (S.empty())
                {
                    flag = false;
                    break;
                }
                else
                    S.pop();
            }
        }

        if (!S.empty() || !flag)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }
}