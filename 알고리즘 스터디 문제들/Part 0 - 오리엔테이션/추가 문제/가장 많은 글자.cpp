#include <iostream>
#include <string>
using namespace std;

int main()
{
    int alphabet[26] = {};

    int max_size = 0;
    string input;
    while (cin >> input) // EOF
    {
        for (size_t i = 0; i < input.length(); i++)
        {
            alphabet[input[i] - 'a']++;
            if (alphabet[input[i] - 'a'] > max_size)
                max_size = alphabet[input[i] - 'a'];
        }
    }

    for (size_t i = 0; i < 26; i++)
    {
        if (alphabet[i] == max_size)
            cout << (char)('a' + i);
    }
}