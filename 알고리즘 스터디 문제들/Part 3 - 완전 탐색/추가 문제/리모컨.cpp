/* 
리모컨으로 채널을 옮기는 경우는 세가지 경우가 존재한다.

1. +버튼이나 -버튼만을 이용하는 경우
2. 숫자 버튼으로 바로 그 채널로 이동하는 경우
3. 숫자 버튼으로 근처 채널로 이동하고 +/-버튼을 이용하는 경우

*/

#include <iostream>
#include <array>
#include <string>
using namespace std;

array<bool, 10> B = {}; // B[i] == 숫자 i 버튼이 고장나 있는가?

// 누를 수 있는 숫자인지 확인하고, 가능하면 그 자릿수를 return
int check(int N)
{
    if (N < 0)
        return false;

    string Nstr = to_string(N);
    for (size_t i = 0; i < Nstr.length(); i++)
    {
        if (B[Nstr[i] - '0'])
            break;
        else if (i == Nstr.length() - 1)
            return i + 1;
    }
    return 0;
}

int main()
{
    int N, M, tmp;
    cin >> N >> M;
    for (size_t i = 0; i < M; i++)
    {
        cin >> tmp;
        B[tmp] = true;
    }

    int ans = 1'000'000;
    int chk;

    if (ans > abs(N - 100)) // 1번
        ans = abs(N - 100);

    chk = check(N);
    if (chk && ans > chk) // 2번
        ans = chk;
    else if (M != 10) // 3번
    {
        for (int i = 1; check(N + i) + i <= ans; i++)
        {
            chk = check(N + i);
            if (chk && chk + i < ans)
                ans = chk + i;

            chk = check(N - i);
            if (chk && chk + i < ans)
                ans = chk + i;
        }
    }

    cout << ans;
}
