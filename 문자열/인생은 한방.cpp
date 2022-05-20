#include <iostream>
#include <string>
using namespace std;

int cache[100001];

int main()
{
    int N;
    string str;
    cin >> N >> str;

    cache[0] = 1;
    for (int i = 1; i < N; ++i)
        cache[i] = (abs(str[i] - str[i - 1]) == 1) ? cache[i - 1] + 1 : 1;

    bool flag = false;
    for (int i = 0; i < N; ++i)
    {
        if (cache[i] >= 5)
            flag = true;
    }

    cout << (flag ? "YES" : "NO") << '\n';
}