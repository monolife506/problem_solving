#include <iostream>
#include <string>
using namespace std;

int main()
{
    string mystr;

    // 띄어쓰기를 포함하여 Enter를 치기 전까지 입력받음
    getline(cin, mystr); 
    cout << mystr << '\n';

    // 띄어쓰기 전 까지만 입력받음
    cin >> mystr;
    cout << mystr << '\n';
}