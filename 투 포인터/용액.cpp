// 2467번: 용액

#include <iostream>
using namespace std;

int N;
int num[100000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
        cin >> num[i];

    int minDiff = 2'000'000'000;
    int S = 0, E = N - 1;
    int minS, minE;
    while (S != E)
    {
        int curDiff = abs(num[S] + num[E]);
        if (minDiff > curDiff)
        {
            minDiff = curDiff;
            minS = S;
            minE = E;
        }

        int diffS = abs(num[S + 1] + num[E]);
        int diffE = abs(num[S] + num[E - 1]);
        if (diffS < diffE)
            S += 1;
        else
            E -= 1;
    }

    cout << num[minS] << " " << num[minE];
}