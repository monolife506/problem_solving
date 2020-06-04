// 1074번: Z

#include <iostream>
#include <cmath>
using namespace std;

int r, c;
int Z(int N, int R, int C, int sum)
{
    int ans;
    if (N == 1)
    {
        if (r == R && c == C)
            ans = sum;
        else if (r == R && c == C + 1)
            ans = sum + 1;
        else if (r == R + 1 && c == C)
            ans = sum + 2;
        else if (r == R + 1 && c == C + 1)
            ans = sum + 3;
        return ans;
    }

    int d = (int)pow(2, N - 1);
    if (r >= R + d && c >= C + d)
        ans = Z(N - 1, R + d, C + d, sum + d * d * 3);
    else if (r >= R + d)
        ans = Z(N - 1, R + d, C, sum + d * d * 2);
    else if (c >= C + d)
        ans = Z(N - 1, R, C + d, sum + d * d);
    else
        ans = Z(N - 1, R, C, sum);

    return ans;
}

int main()
{
    int N;
    cin >> N >> r >> c;
    cout << Z(N, 0, 0, 0);
}