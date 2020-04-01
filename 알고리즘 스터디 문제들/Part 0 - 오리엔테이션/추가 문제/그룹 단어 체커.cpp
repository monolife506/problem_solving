#include <iostream>
#include <string>
using namespace std;

int main()
{
    size_t N;
    cin >> N;

    size_t cnt = 0;
    string input;

    for (size_t i = 0; i < N; i++)
    {
        cin >> input;

        bool flags[26] = {}; // false로 초기화
        for (size_t j = 0; j < input.length(); j++)
        {
            if (!flags[input[j] - 'a'])
                flags[input[j] - 'a'] = true;
            else if (flags[input[j] - 'a'] && input[j - 1] != input[j])
                break;

            if (j == input.length() - 1)
                cnt++;
        }
    }

    cout << cnt;
}