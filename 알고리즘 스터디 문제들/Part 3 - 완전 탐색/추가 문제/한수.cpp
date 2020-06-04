#include <iostream>
#include <string>
using namespace std;

bool han(int N)
{
    bool flag = true;
    string str = to_string(N);
    for (size_t i = 2; i < str.length(); i++)
    {
        if (str[i] - str[i - 1] != str[i - 1] - str[i - 2])
            flag = false;
    }
    return flag;
}

int main()
{
    int N;
    cin >> N;

    int cnt = 0;
    for (size_t i = 1; i <= N; i++)
    {
        if (han(i))
            cnt++;
    }
    cout << cnt;
}
