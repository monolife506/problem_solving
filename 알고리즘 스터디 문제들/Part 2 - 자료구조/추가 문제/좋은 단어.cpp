#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    size_t N;
    cin >> N;

    int cnt = 0;
    string input;
    for (size_t i = 0; i < N; i++)
    {
        cin >> input;
        stack<char> S;
        for (size_t j = 0; j < input.length(); j++)
        {
            if (S.empty())
                S.push(input[j]);
            else if (input[j] == 'A')
            {
                if (S.top() == 'A')
                    S.pop();
                else
                    S.push('A');
            }
            else
            {
                if (S.top() == 'B')
                    S.pop();
                else
                    S.push('B');
            }
        }

        if (S.empty())
            cnt++;
    }
    cout << cnt;
}