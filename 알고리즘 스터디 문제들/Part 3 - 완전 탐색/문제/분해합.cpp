#include <iostream>
#include <string>
using namespace std;

// 분해합을 구하는 함수
int decomp(int N)
{
    string N_str = to_string(N);
    for (size_t i = 0; i < N_str.length(); i++)
        N += (N_str[i] - '0');
    return N;
}

int main()
{
    size_t N;
    cin >> N;

    for (size_t i = 1; i < N; i++)
    {
        if (decomp(i) == N)
        {
            cout << i;
            break;
        }
        else if (i == N - 1)
            cout << 0;
    }
}