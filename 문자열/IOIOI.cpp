// 5525번: IOIOI

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N, M, ans = 0;
    string S, P = "IOI";
    cin >> N >> M >> S;

    for (size_t i = 0; i < M; i++)
    {
        int tmp = 0;
        while (P == S.substr(i, 3) && i < S.size() - 2)
        {
            tmp++;
            i += 2;
        }

        if (tmp - N + 1 > 0)
            ans += tmp - N + 1;
    }
    cout << ans;
}