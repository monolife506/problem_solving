#include <algorithm>
#include <iostream>
using namespace std;

int arr[50];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    sort(arr, arr + N);

    int ans = 0;
    for (int i = 0; i <= N; ++i)
    {
        if (i < N && arr[i] <= 0)
        {
            if (i % 2 == 1)
                ans += arr[i] * arr[i - 1];
        }
        else
        {
            if (i % 2 == 1)
                ans += arr[i - 1];

            break;
        }
    }
    for (int i = 0; i <= N; ++i)
    {
        int cur = N - (i + 1);
        int pre = N - i;

        if (cur >= 0 && arr[cur] > 0)
        {
            if (i % 2 == 1)
            {
                if (arr[cur] * arr[pre] >= arr[cur] + arr[pre])
                    ans += arr[cur] * arr[pre];
                else
                    ans += arr[cur] + arr[pre];
            }
        }
        else
        {
            if (i % 2 == 1)
                ans += arr[pre];

            break;
        }
    }

    cout << ans << '\n';
}

/*

-3 -2 -1 0 | 1 2 -> (-3 * -2) + (-1 * 0) + (1 * 2)
-2 -1 0 | 1 2 3 -> (-2 * -1) + 0 + 1 + (3 * 2)
-3 -2 -1 0 | 1 2 3 -> (-3 * -2) + (-1 * 0) + 1 + (2 * 3)

*/