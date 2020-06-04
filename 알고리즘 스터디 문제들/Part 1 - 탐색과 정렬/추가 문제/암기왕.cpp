#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool binarySearch(int target, const vector<int> &arr)
{
    int left = 0;
    int right = arr.size() - 1;
    int mid;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == target)
            return true;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    size_t T; // unsigned long long과 같은 의미입니다.
    cin >> T;

    for (size_t i = 0; i < T; i++)
    {
        size_t N;
        cin >> N;
        vector<int> note1(N); // 숫자를 찾을 배열
        for (size_t j = 0; j < N; j++)
            cin >> note1[j];

        size_t M;
        cin >> M;
        vector<int> note2(M); // 찾아야 할 정수들
        for (size_t j = 0; j < M; j++)
            cin >> note2[j];

        sort(note1.begin(), note1.end());
        for (size_t j = 0; j < M; j++)
            cout << binarySearch(note2[j], note1) << '\n';
    }
}