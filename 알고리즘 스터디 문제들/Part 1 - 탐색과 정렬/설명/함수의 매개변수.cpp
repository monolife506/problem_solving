#include <iostream>
using namespace std;

int passByValue(int arg1, int arg2)
{
    arg1 += 20; // 매개변수 1에 20 더하기
    arg2 += 30; // 매개변수 2에 30 더하기
    return arg1 + arg2;
}

int passByReference(int &arg1, int &arg2)
{
    arg1 += 20; // 매개변수 1에 20 더하기
    arg2 += 30; // 매개변수 2에 30 더하기
    return arg1 + arg2;
}

int main()
{
    int num1;
    int num2;
    cin >> num1 >> num2; // 인수 num1, num2의 값 입력

    cout << passByValue(num1, num2) << '\n';
    cout << "passbyValue 이후 인수 num1, num2의 값: ";
    cout << num1 << " " << num2 << '\n'; // 인수 num1, num2의 값은 일정하다.

    cout << passByReference(num1, num2) << '\n';
    cout << "passbyReference 이후 인수 num1, num2의 값: ";
    // 인수 num1, num2의 값에 각각 20, 30씩 더해져 있다.
    cout << num1 << " " << num2 << '\n';
}
