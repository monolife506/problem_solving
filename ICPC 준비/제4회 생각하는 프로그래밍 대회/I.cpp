#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int N;
int prefer_man[201][201]; // 남자의 선호도
int prefer_woman[201][201]; // 여자의 선호도
unordered_map<string, int> name_man; // 남자의 이름
unordered_map<string, int> name_woman; // 여자의 이름

int man_match[200];
int woman_match[200];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str1, str2;
    cin >> N;

    for (size_t i = 1; i <= N; i++) {
        cin >> str1;
        name_man[str1] = i;
    }
    for (size_t i = 1; i <= N; i++) {
        cin >> str1;
        name_woman[str1] = i;
    }

    for (size_t i = 0; i < N; i++) {
        cin >> str1;
        for (size_t j = N; j > 0; j--) {
            cin >> str2;
            prefer_man[name_man[str1]][name_woman[str2]] = j;
        }
    }
    for (size_t i = 0; i < N; i++) {
        cin >> str1;
        for (size_t j = N; j > 0; j--) {
            cin >> str2;
            prefer_woman[name_woman[str1]][name_man[str2]] = j;
        }
    }
}

// 이분 매칭
//