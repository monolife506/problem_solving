#include <iostream>
using namespace std;

// 달팽이가 나무를 오르는데 걸린 일수를 찾는다.
int binarySearch(int A, int B, int V)
{
    int mid;
    int ans;

    // 최소 1일이 걸리지만, 0으로 잡아둔다.
    // 해의 최솟값을 모를 경우 적당히 작은 정수로 지정해도 된다.
    // ex) 0, 음수가 가능할 경우 int의 최솟값인 INT32_MIN
    int left = 0;

    // A == 2, B == 1인 경우 최대 소요 날짜가 V - 1일이다.
    // left와 마찬가지로 해의 최댓값을 모를 경우 적당히 큰 정수로 지정해도 된다.
    // ex) int의 최댓값인 INT32_MAX
    int right = V;

    while (left <= right)
    {
        mid = (left + right) / 2;

        // 만약 mid일차동안 오른 최대 거리가
        // V보다 큰 경우
        if ((A - B) * (mid - 1) + A >= V)
        {
            // mid - 1일차가 포함된 범위에서
            // 조건을 만족하는 값이 존재한다면 최솟값이 갱신될 것이고,
            // 없다면 최솟값 그대로 left > right가 되어 루프에서 탈출할 것이다.
            ans = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    return ans;
}

int main()
{
    int A, B, V;
    cin >> A >> B >> V;
    cout << binarySearch(A, B, V);
}