#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int ALPHABET_CNT = 26;

bool check(const vector<int> &S_cnt, const vector<int> &T_cnt, bool is_same_length)
{
    int offset = 0;
    bool flag = false; // 단 한 글자만 다른가?

    for (size_t i = 0; i < ALPHABET_CNT; i++)
    {
        if (S_cnt[i] == T_cnt[i])
            continue;
        if (flag)
            return false;
        if (abs(S_cnt[i] - T_cnt[i]) >= 2)
            return false;

        if (abs(offset) == 1)
        {
            offset += S_cnt[i] - T_cnt[i];
            if (offset != 0)
                return false;
            flag = true;
            continue;
        }

        offset += S_cnt[i] - T_cnt[i];
    }

    return (is_same_length) ? flag : true;
}

bool isPassword(const string &S, const string &T, const vector<int> &S_cnt)
{
    if (S.length() > T.length())
        return false;

    vector<int> T_cnt(ALPHABET_CNT, 0);
    bool is_same_length = (S.length() == T.length());

    for (size_t i = 0; i < T.length(); i++)
    {
        T_cnt[T[i] - 'a']++;
        if (i >= S.length())
            T_cnt[T[i - S.length()] - 'a']--;

        if (i >= S.length() - 1)
            if (check(S_cnt, T_cnt, is_same_length))
                return true;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string S;
    int N;
    cin >> S >> N;

    vector<int> S_cnt(ALPHABET_CNT, 0);
    for (const char &chr : S)
        S_cnt[chr - 'a']++;

    for (size_t i = 0; i < N; i++)
    {
        string T;
        cin >> T;
        cout << (isPassword(S, T, S_cnt) ? "YES" : "NO") << '\n';
    }
}