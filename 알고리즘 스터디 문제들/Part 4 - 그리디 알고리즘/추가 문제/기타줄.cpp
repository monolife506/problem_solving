#include <iostream>
using namespace std;

int main()
{
    size_t N, M;
    cin >> N >> M;

    int P, S;
    int minP = 1000;
    int minS = 1000;
    for (size_t i = 0; i < M; i++)
    {
        cin >> P >> S;
        if (minP > P)
            minP = P;
        if (minS > S)
            minS = S;
    }

    int total = 0;
    if (6 * minS <= minP)
        total = minS * N;
    else
    {
        total += (N / 6) * minP;
        total += (minP > (N % 6) * minS) ? (N % 6) * minS : minP;
    }
    cout << total;
}