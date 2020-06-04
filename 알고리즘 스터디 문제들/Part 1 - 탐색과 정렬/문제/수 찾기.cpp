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
        else if (arr[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return false;
}

int main()
{
    size_t N, M;

    cin >> N;
    vector<int> v1(N);
    for (size_t i = 0; i < N; i++)
        cin >> v1[i];

    cin >> M;
    vector<int> v2(M);
    for (size_t i = 0; i < M; i++)
        cin >> v2[i];

    sort(v1.begin(), v1.end());
    for (size_t i = 0; i < M; i++)
        cout << binarySearch(v2[i], v1) << '\n';
}