#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;

    int alphabets[26];

    for (size_t i = 0; i < 26; i++)
        alphabets[i] = -1;
    for (size_t j = 0; j < str.length(); j++)
    {
        if (alphabets[str[j] - 'a'] == -1)
            alphabets[str[j] - 'a'] = j;
    }
    for (size_t k = 0; k < 26; k++)
        cout << alphabets[k] << " ";
}