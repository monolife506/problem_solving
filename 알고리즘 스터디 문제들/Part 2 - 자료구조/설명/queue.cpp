#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> Q;

    int x;
    cin >> x;

    Q.push(10);
    cout << "push 10\n";
    Q.push(25);
    cout << "push 25\n";
    Q.push(60);
    cout << "push 60\n";
    Q.push(x);
    cout << "push " << x << "\n\n";

    cout << "Q.front() == " << Q.front() << '\n'; // 10
    cout << "Q.back() == " << Q.back() << '\n';   // x
    cout << "Q.empty() == " << Q.empty() << '\n'; // 0 (false)
    cout << "Q.size() == " << Q.size() << "\n\n"; // 4

    // 큐가 비기 전까지 아래 내용을 반복한다.
    while (!Q.empty())
    {
        cout << "Q.front() == " << Q.front() << '\n';
        cout << "Q.back() == " << Q.back() << '\n'; // x
        Q.pop();
        cout << "poped\n";
    }

    cout << "Q.empty() == " << Q.empty() << '\n'; // 1 (true)
    cout << "Q.size() == " << Q.size();           // 0
}