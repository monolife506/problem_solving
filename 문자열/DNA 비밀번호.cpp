#include <iostream>
#include <string>
using namespace std;

int min_cnt[4], cnt[4];

bool check()
{
    for (int i = 0; i < 4; ++i)
    {
        if (cnt[i] < min_cnt[i])
            return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int S, P;
    cin >> S >> P;

    string str;
    cin >> str;

    cin >> min_cnt[0] >> min_cnt[1] >> min_cnt[2] >> min_cnt[3];
    for (int i = 0; i < P; ++i)
    {
        if (str[i] == 'A')
            ++cnt[0];
        else if (str[i] == 'C')
            ++cnt[1];
        else if (str[i] == 'G')
            ++cnt[2];
        else
            ++cnt[3];
    }

    int ans = check();
    for (int i = P; i < S; ++i)
    {
        if (str[i] == 'A')
            ++cnt[0];
        else if (str[i] == 'C')
            ++cnt[1];
        else if (str[i] == 'G')
            ++cnt[2];
        else
            ++cnt[3];

        if (str[i - P] == 'A')
            --cnt[0];
        else if (str[i - P] == 'C')
            --cnt[1];
        else if (str[i - P] == 'G')
            --cnt[2];
        else
            --cnt[3];

        ans += check();
    }

    cout << ans << '\n';
}