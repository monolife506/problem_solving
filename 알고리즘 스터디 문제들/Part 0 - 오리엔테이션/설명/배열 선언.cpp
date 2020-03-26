#include <iostream>
using namespace std;

int main()
{
    const unsigned int ARRAY_LENGTH = 10;

    // 크기가 10인 built-in array 선언, 내부의 값은 모두 0으로 초기화
    int builtinArray[ARRAY_LENGTH] = {}; 

    for (size_t i = 0; i < ARRAY_LENGTH; i++)
    {
       builtinArray[i] = i + 1;
    }
    
    cout << builtinArray[5] << '\n'; // 6 - 모든 요소에 바로 접근 가능
    // cout << builtinArray[10] << '\n' - 에러 발생

    for (size_t i = 0; i < ARRAY_LENGTH; i++)
    {
        cout << builtinArray[i] << '\n';
    }
}