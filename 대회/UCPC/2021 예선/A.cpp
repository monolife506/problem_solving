#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;

    int A = 999, B = 999;
    for (int i = 1; i <= 3; ++i)
    {
        if (i > str.size())
            continue;

        int a = stoi(str.substr(0, i));
        int b = a;
        int j = 0;

        bool flag = true;
        while (true)
        {
            int len = to_string(b).size();
            if (j + len > str.size())
            {
                flag = false;
                break;
            }

            if (stoi(str.substr(j, len)) == b)
            {
                if (j + len == str.size())
                    break;

                j += len;
                ++b;
            }
            else
            {
                flag = false;
                break;
            }
        }

        if (flag && A > a)
        {
            A = a;
            B = b;
        }
    }

    cout << A << " " << B << '\n';
}