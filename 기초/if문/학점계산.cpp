#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string grade;
    cin >> grade;
    if (grade[0] == 'A')
    {
        if (grade[1] == '+')
        {
            cout << "4.3" << '\n';
        }
        else if (grade[1] == '0')
        {
            cout << "4.0" << '\n';
        }
        else
        {
            cout << "3.7" << '\n';
        }
    }
    else if (grade[0] == 'B')
    {
        if (grade[1] == '+')
        {
            cout << "3.3" << '\n';
        }
        else if (grade[1] == '0')
        {
            cout << "3.0" << '\n';
        }
        else
        {
            cout << "2.7" << '\n';
        }
    }
    else if (grade[0] == 'C')
    {
        if (grade[1] == '+')
        {
            cout << "2.3" << '\n';
        }
        else if (grade[1] == '0')
        {
            cout << "2.0" << '\n';
        }
        else
        {
            cout << "1.7" << '\n';
        }
    }
    else if (grade[0] == 'D')
    {
        if (grade[1] == '+')
        {
            cout << "1.3" << '\n';
        }
        else if (grade[1] == '0')
        {
            cout << "1.0" << '\n';
        }
        else
        {
            cout << "0.7" << '\n';
        }
    }
    else
    {
        cout << "0.0" << '\n';
    }
}