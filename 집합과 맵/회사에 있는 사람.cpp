#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    set<string> s;
    for (int i = 0; i < n; ++i)
    {
        string name, log;
        cin >> name >> log;
        if (log == "enter")
            s.insert(name);
        else // log == 'leave'
            s.erase(name);
    }

    for (auto it = s.rbegin(); it != s.rend(); ++it)
        cout << *it << '\n';
}