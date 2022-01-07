#include <iostream>
using namespace std;
const int MAX = 100000;

int N, histogram[MAX + 1];

int divide_and_conquer(int left, int right)
{
    if (left == right)
        return histogram[left];

    int mid = (left + right) / 2;
    int ret = max(divide_and_conquer(left, mid), divide_and_conquer(mid + 1, right));

    // 중앙 히스토그램의 넓이 구하기
    int mid_height = min(histogram[mid], histogram[mid + 1]);
    int L = mid, R = mid + 1, nxt;
    int mid_area = (R - L + 1) * mid_height;

    while (L > left || R < right)
    {
        if (L == left || R == right)
            nxt = (R == right) ? --L : ++R;
        else
            nxt = (histogram[L - 1] > histogram[R + 1]) ? --L : ++R;

        mid_height = min(mid_height, histogram[nxt]);
        mid_area = max(mid_area, (R - L + 1) * mid_height);
    }

    return max(ret, mid_area);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (size_t i = 0; i < N; i++)
        cin >> histogram[i];

    cout << divide_and_conquer(0, N - 1) << '\n';
}