#include <iostream>
#include <string>
using namespace std;

int main()
{
    int alphabet[26] = {};
    int max_cnt = 0;

    string input;
    cin >> input;

    for (size_t i = 0; i < input.length(); i++)
    {
        int index;

        if (input[i] >= 'a')
            index = input[i] - 'a';
        else
            index = input[i] - 'A';

        if (++alphabet[index] > max_cnt)
            max_cnt = alphabet[index];
    }

    char max_alphabet;
    bool flag = false; // 가장 많은 알파벳을 하나만 찾았는지 확인
    for (size_t i = 0; i < 26; i++)
    {
        if (alphabet[i] == max_cnt && !flag)
        {
            max_alphabet = i + 'A';
            flag = true;
        }
        else if (flag) // 가장 많은 알파벳이 하나 이상인 경우
        {
            if (alphabet[i] == max_cnt && i + 'A' != max_alphabet)
            {
                flag = false;
                break;
            }
        }
    }

    if (flag)
        cout << max_alphabet;
    else
        cout << "?";
}