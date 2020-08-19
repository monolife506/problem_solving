// 9935번: 문자열 폭발

#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str, target;
    cin >> str >> target;

    int cur = 0;
    deque<pair<int, char>> D;
    for (char chr : str)
    {
        if (chr == target[cur])
            cur++;
        else
            cur = (chr == target[0]);

        D.push_back(make_pair(cur, chr));
        if (cur == target.size())
        {
            for (size_t i = 0; i < cur; i++)
                D.pop_back();

            if (!D.empty())
                cur = D.back().first;
            else
                cur = 0;
        }
    }

    if (D.empty())
        cout << "FRULA";
    else
    {
        for (size_t i = 0; i < D.size(); i++)
            cout << D[i].second;
    }
}

// 12ab1212abab
// 1234
// 121234
// 1234
// FRULA

// mirkovC4nizCC44
// 00000012
// 000000000112
// 00000000012
// mirkovniz