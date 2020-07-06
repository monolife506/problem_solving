#include <iostream>
#include <string>
using namespace std;

int main()
{
    bool flag[4] = {};
    string input;
    getline(cin, input);
    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] == 'U' && !flag[0])
        {
            flag[0] = true;
        }

        if (input[i] == 'C')
        {
            if (flag[0] && !flag[1])
            {
                flag[1] = true;
            }
            else if (flag[2] && !flag[3])
            {
                flag[3] = true;
            }
        }

        if (flag[1] && !flag[2] && input[i] == 'P')
        {
            flag[2] = true;
        }
    }

    cout << ((flag[3]) ? "I love UCPC" : "I hate UCPC");
}