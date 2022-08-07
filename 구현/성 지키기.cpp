#include <iostream>
#include <string>
using namespace std;

bool flag[2][50];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        for (int j = 0; j < M; ++j)
        {
            if (str[j] == 'X')
            {
                flag[0][i] = true;
                flag[1][j] = true;
            }
        }
    }

    int cnt[2] = {};
    for (int i = 0; i < N; ++i)
    {
        if (!flag[0][i])
            ++cnt[0];
    }
    for (int i = 0; i < M; ++i)
    {
        if (!flag[1][i])
            ++cnt[1];
    }

    cout << max(cnt[0], cnt[1]) << '\n';
}

/*

X....
X....
XX.XX
.....
X....

*/