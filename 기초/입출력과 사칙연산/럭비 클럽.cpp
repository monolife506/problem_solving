#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string name;
    int age, w;
    while (true)
    {
        cin >> name >> age >> w;
        if (name == "#" && age == 0 && w == 0)
            break;

        cout << name << (age > 17 || w >= 80 ? " Senior" : " Junior") << '\n';
    }
}