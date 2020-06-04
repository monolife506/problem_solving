#include <iostream>
#include <array>
using namespace std;

int N, S;
int cnt = 0;
array<int, 20> arr;

void backtrack(int idx, int total)
{
    if (idx == N)
    {
        if (total == S)
            cnt++;
        return;
    }

    backtrack(idx + 1, total);
    backtrack(idx + 1, total + arr[idx]);
}

int main()
{
    cin >> N >> S;
    for (size_t i = 0; i < N; i++)
        cin >> arr[i];

    backtrack(0, 0);
    cout << ((S == 0) ? cnt - 1 : cnt);
}