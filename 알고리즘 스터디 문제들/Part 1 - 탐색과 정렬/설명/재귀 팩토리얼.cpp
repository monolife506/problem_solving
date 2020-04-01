#include <iostream>
using namespace std;

int fac(int N)
{
    if (N == 1) // 탈출 조건
        return 1;

    // 자기 자신을 다시 호출함
    return fac(N - 1) * N;
}

int main()
{
    int input;
    cin >> input;
    cout << fac(input);
}