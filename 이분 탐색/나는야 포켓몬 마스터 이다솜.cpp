// 1620번: 나는야 포켓몬 마스터 이다솜

#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <algorithm>
using namespace std;

bool is_number(const string &s)
{
    return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<string, int> mapByStr;
    map<int, string> mapByNum;

    int N, M;
    string input;
    cin >> N >> M;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> input;

        mapByNum[i] = input;
        mapByStr[input] = i;
    }

    for (size_t i = 0; i < M; i++)
    {
        cin >> input;
        if (is_number(input))
            cout << mapByNum[stoi(input)] << '\n';
        else
            cout << mapByStr[input] << '\n';
    }
}