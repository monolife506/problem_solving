// 18119번: 단어 암기
// <bitset> 사용해보기

#include <iostream>
#include <string>
#include <bitset>
using namespace std;

bitset<26> words[10000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    string str;
    for (size_t i = 0; i < N; i++)
    {
        cin >> str;
        for (char &chr : str)
            words[i][chr - 'a'] = 1;
    }

    bitset<26> cur;
    cur.set();
    for (size_t i = 0; i < M; i++)
    {
        int O;
        char X;
        cin >> O >> X;
        cur.flip(X - 'a');

        int cnt = 0;
        for (size_t j = 0; j < N; j++)
        {
            if ((words[j] & cur) == words[j])
                cnt++;
        }
        cout << cnt << '\n';
    }
}