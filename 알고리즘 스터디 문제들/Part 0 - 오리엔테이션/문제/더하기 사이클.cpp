#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int cnt = 0;
    int tmp = N;
    do
    {
        int firstNum = tmp / 10;
        int secondNum = tmp % 10;
        int sum = firstNum + secondNum;

        tmp = (secondNum * 10) + (sum % 10);
        cnt++;

    } while (tmp != N);
    cout << cnt;
}
