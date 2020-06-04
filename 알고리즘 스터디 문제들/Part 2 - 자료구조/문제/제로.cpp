#include <iostream>
#include <stack>
using namespace std;

int main()
{
    size_t K;
    cin >> K;

    int input;
    stack<int> S;
    for (size_t i = 0; i < K; i++)
    {
        cin >> input;

        if (input == 0)
            S.pop();
        else
            S.push(input);
    }

    int sum = 0;
    while (!S.empty())
    {
        sum += S.top();
        S.pop();
    }
    cout << sum;
}