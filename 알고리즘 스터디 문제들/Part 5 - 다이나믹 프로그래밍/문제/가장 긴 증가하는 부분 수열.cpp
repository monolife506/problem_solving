#include <iostream>
#include <array>
using namespace std;

array<int, 1000 + 1> A;   // A[i] = 수열의 i번째 숫자
array<int, 1000 + 1> len; // len[i] = i번째에서 끝나는 증가하는 부분 수열의 최대 길이

int main()
{
    size_t N;
    cin >> N;
    for (size_t i = 1; i <= N; i++)
        cin >> A[i];

    int max_len = 1; // 가장 긴 증가하는 부분 수열의 길이
    len[0] = 0;
    for (size_t i = 0; i <= N - 1; i++)
    {
        for (size_t j = i + 1; j <= N; j++)
        {
            if (A[i] < A[j] && len[i] + 1 >= len[j])
                len[j] = len[i] + 1;
            if (max_len < len[j])
                max_len = len[j];
        }
    }
    cout << max_len;
}