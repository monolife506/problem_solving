// 5086번 : 배수와 약수

#include <iostream>
using namespace std;

int main()
{
    size_t A, B;
    while (A != 0 && B != 0)
    {
        cin >> A >> B;
        if (A == 0 && B == 0)
            break;
        else if (B % A == 0)
            cout << "factor";
        else if (A % B == 0)
            cout << "multiple";
        else
            cout << "neither";
        cout << '\n';
    } 
}