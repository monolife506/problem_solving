#include <iostream>
using namespace std;

int A[10000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    int lo = 0, hi = 0, sum = 0, ans = 0;
    while (true)
    {
        if (sum >= M)
            sum -= A[lo++];
        else if (hi == N)
            break;
        else
            sum += A[hi++];

        if (sum == M)
            ++ans;
    }

    cout << ans << '\n';
}