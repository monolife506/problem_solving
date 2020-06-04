#include <iostream>
#include <string>
using namespace std;

// const + pass-by-reference로 인수룰 전달한 함수.
// 값을 변경하지 않는 array나 string 같은 경우,
// 이렇게 전달하면 유용하다.
string func(const string &str)
{
    // ERROR: const 선언된 매개변수는 값을 변경할 수 없다.
    // str = "ddd"
    return str;
}

int main()
{
    const int CONST_VARIABLE = 10;

    // ERROR: const 선언된 변수는 값을 변경할 수 없다.
    // CONST_VARIABLE = 20;
}