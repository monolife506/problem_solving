#include <iostream>
using namespace std;

int main()
{
    // char형의 숫자 - '0'의 정수값은
    // char가 나타내는 숫자의 값이다.
    char chrFive = '5';
    int five = chrFive - '0';
    cout << five << '\n';

    // A ~ Z, a ~ z가 순서대로 있음을 이용해
    // 글자가 알파벳인가의 여부를 다음과 같이
    // 판단할 수 있다.
    char unknownChr = 'P';
    if ('A' <= unknownChr && 'Z' >= unknownChr)
    {
        cout << "unknownChr is uppercase alphabet";
    }
    else if ('a' <= unknownChr && 'z' >= unknownChr)
    {
        cout << "unknownChr is lowercase alphabet";
    }
    cout << '\n';

    // char의 아스키 코드를 확인하고 싶다면 다음과 같이
    // char를 int로 바꾸어 확인하면 된다.
    cout << (int)unknownChr;
}