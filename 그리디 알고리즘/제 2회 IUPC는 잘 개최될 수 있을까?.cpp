#include <algorithm>
#include <iostream>
using namespace std;

int A[1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    sort(A, A + N, greater<int>());

    int sum = 0, ans = 0;
    bool flag = false;
    for (int i = 0; i < N; ++i)
    {
        sum += A[i];
        ans++;

        if (sum >= M * K)
        {
            flag = true;
            break;
        }
    }

    if (flag)
        cout << ans << '\n';
    else
        cout << "STRESS" << '\n';
}