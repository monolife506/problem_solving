#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> D;

    D.push_front(5);
    D.push_front(10);
    D.push_back(20);
    D.push_back(25);

    // 현재 Deque의 내용: 10 5 20 25
    cout << "D[1] == " << D[1] << '\n'; // 5

    D.push_front(100);
    D.push_back(75);

    // 현재 Deque의 내용: 100 10 5 20 25 75
    cout << "\nD.front() == " << D.front()        // 100
         << "\nD.back() == " << D.back() << '\n'; // 75

    D.pop_back();
    D.pop_back();
    D.push_front(30);
    D.push_front(50);

    // 현재 Deque의 내용: 50 30 100 10 5 20
    cout << "\nD[2] == " << D[2]          // 100
         << "\nD[4] == " << D[4] << '\n'; // 5

    D.pop_front();
    D.pop_front();
    D.pop_front();

    // 현재 Deque의 내용: 10 5 20
    cout << "\nD.front() == " << D.front()        // 10
         << "\nD.back() == " << D.back() << '\n'; // 20
}