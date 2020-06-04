#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int N, M;
array<int, 8> num;        // 입력한 숫자를 저장하는 배열
array<int, 8> ans;        // 수열들을 저장하는 배열
array<bool, 8> used = {}; // 특정 숫자를 사용했는지 확인하는 배열

void backtracking(int cnt)
{
    if (cnt == M)
    {
        for (size_t i = 0; i < M; i++)
            cout << ans[i] << " ";

        cout << '\n';
        return;
    }

    for (size_t i = 0; i < N; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            ans[cnt] = num[i];
            backtracking(cnt + 1);
            used[i] = false;
        }
    }
}

int main()
{
    cin >> N >> M;
    for (size_t i = 0; i < N; i++)
        cin >> num[i];

    sort(num.begin(), num.begin() + N);
    backtracking(0);
}