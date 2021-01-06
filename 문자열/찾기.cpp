// 1786번: 찾기
// KMP 알고리즘

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Failure Fuction의 값 초기화
vector<int> getfail(const string& pat)
{
    vector<int> fail(pat.size(), 0);
    for (size_t i = 1, j = 0; i < pat.size(); i++) {
        while (j > 0 && pat[i] != pat[j])
            j = fail[j - 1];

        if (pat[i] == pat[j])
            fail[i] = ++j;
    }

    return fail;
}

// KMP 알고리즘
vector<int> kmp(const string& str, const string& pat, const vector<int>& fail)
{
    // 패턴의 시작 위치들
    vector<int> posv;

    // i: str에서 탐색 위치
    // j: pat에서의 탐색 위치
    for (size_t i = 0, j = 0; i < str.size(); i++) {
        while (j > 0 && str[i] != pat[j])
            j = fail[j - 1];

        if (str[i] == pat[j]) {
            if (j == pat.size() - 1) // 패턴 일치
            {
                posv.push_back(i - (pat.size() - 1));
                j = fail[j];
            } else // 중간 과정
                j++;
        }
    }
    return posv;
}

int main()
{
    string T, P;
    getline(cin, T);
    getline(cin, P);

    vector<int> posv = kmp(T, P, getfail(T, P));
    cout << posv.size() << '\n';
    for (int& pos : posv)
        cout << pos + 1 << '\n';
}