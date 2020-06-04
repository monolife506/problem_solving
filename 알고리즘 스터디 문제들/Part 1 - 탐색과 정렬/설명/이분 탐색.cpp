#include <iostream>
#include <vector>
using namespace std;

bool binary_search(int left, int right, int target, const vector<int> &arr)
{
    if (left > right) // 탈출 조건: 값이 vector 내부에 존재하지 않음
        return false;

    int mid = (left + right) / 2;

    // 탈출 조건: 값이 vector 내부에 존재함
    if (arr[mid] == target)
        return true;
    else if (arr[mid] > target)
        return binary_search(left, mid - 1, target, arr);
    else // arr[mid] < target
        return binary_search(mid + 1, right, target, arr);
}

bool binary_search2(int target, const vector<int> &arr)
{
    int left = 0;
    int right = arr.size() - 1;
    int mid;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (arr[mid] == target) // 탈출 조건: 값이 vector 내부에 존재함
            return true;
        else if (arr[mid] > target)
            right = mid - 1;
        else // arr[mid] < target
            left = mid + 1;
    }

    // while문에서 탈출 => left > right임 => 값이 존재하지 않음
    return false;
}

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    cout << binary_search(0, arr.size() - 1, 9, arr) << '\n';
    cout << binary_search(0, arr.size() - 1, 2, arr) << '\n';
    cout << binary_search2(1, arr) << '\n';
    cout << binary_search2(10, arr) << '\n';
}