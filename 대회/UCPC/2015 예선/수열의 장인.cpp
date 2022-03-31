// 10885번: 수열의 장인

#include <iostream>
using namespace std;
const int MOD = 1000000007;

int arr[100001];
int twoMod[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    twoMod[0] = 1;
    for (size_t i = 0; i < 100000; i++)
        twoMod[i + 1] = (twoMod[i] * 2) % MOD;

    size_t T;
    cin >> T;
    for (size_t tc = 0; tc < T; tc++)
    {
        int N;
        cin >> N;
        for (int i = 1; i <= N; i++)
            cin >> arr[i];

        bool isZero = true;
        bool isMinus = false;
        int cnt, maxCnt = 0;

        // 왼쪽부터 시작
        cnt = 0;
        for (int i = 1; i <= N; i++)
        {
            if (abs(arr[i]) == 2)
                cnt++;
            if (arr[i] == 0)
            {
                cnt = 0;
                isMinus = false;
                continue;
            }
            if (arr[i] < 0)
                isMinus = !isMinus;

            if (!isMinus)
            {
                maxCnt = max(maxCnt, cnt);
                isZero = false;
            }
        }

        // 오른쪽부터 시작
        isMinus = false;
        cnt = 0;
        for (int i = N; i > 0; i--)
        {
            if (abs(arr[i]) == 2)
                cnt++;
            if (arr[i] == 0)
            {
                cnt = 0;
                isMinus = false;
                continue;
            }
            if (arr[i] < 0)
                isMinus = !isMinus;

            if (!isMinus)
            {
                maxCnt = max(maxCnt, cnt);
                isZero = false;
            }
        }

        cout << ((isZero) ? 0 : twoMod[maxCnt]) << '\n';
    }
}

// 양수여야 함
// 범위 내에 2의 개수가 가장 많아야 함
// O(N)

// '0'의 존재