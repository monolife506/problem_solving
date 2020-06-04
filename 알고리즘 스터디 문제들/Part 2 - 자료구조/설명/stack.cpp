#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> S;

    int x;
    cin >> x;

    S.push(10);
    cout << "push 10\n";
    S.push(25);
    cout << "push 25\n";
    S.push(x);
    cout << "push " << x << "\n\n";

    cout << "S.top() == " << S.top() << '\n';     // x
    cout << "S.empty() == " << S.empty() << '\n'; // 0 (false)
    cout << "S.size() == " << S.size() << "\n\n"; // 3

    // 스택이 비기 전까지 아래 내용을 반복한다.
    while (!S.empty())
    {
        cout << "S.top() == " << S.top() << '\n';
        S.pop();
        cout << "poped\n";
    }

    cout << "S.empty() == " << S.empty() << '\n'; // 1 (true)
    cout << "S.size() == " << S.size();           // 0
}