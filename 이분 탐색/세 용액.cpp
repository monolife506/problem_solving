// 2473번: 세 용액

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr ll INF = 3'000'000'000;

ll num[5001];

int main()
{
    int N, I, J, K;
    ll curDiff, minDiff = INF;

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
        cin >> num[i];

    sort(num, num + N);
    for (size_t i = 0; i < N - 2; i++)
    {
        for (size_t j = i + 1; j < N - 1; j++)
        {
            int k = (int)(lower_bound(num + (j + 1), num + N, -(num[i] + num[j])) - num);

            curDiff = INF;
            if (k < N)
                curDiff = abs(num[i] + num[j] + num[k]);
            if (k > j + 1 && curDiff > abs(num[i] + num[j] + num[k - 1]))
                curDiff = abs(num[i] + num[j] + num[--k]);

            if (curDiff < minDiff)
            {
                minDiff = curDiff;
                I = i;
                J = j;
                K = k;
            }
        }
    }

    cout << num[I] << " " << num[J] << " " << num[K];
}