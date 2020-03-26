#include <iostream>
#include <string> // string 사용
using namespace std;

int main()
{
    string mystr = "This is my string";
    cout << mystr << '\n';

    cout << mystr[4] << '\n'; // == ' ';
    
    char mystr_7 = mystr[7];
    char charExample = '5';
    // char myChar = "5" - ERROR

    cout << mystr.length();
    // mystr.length() == mystr.size()
}