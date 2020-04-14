#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

void print_arr(const array<int, 3> &arr)
{
    cout << "[";
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (i == arr.size() - 1)
            cout << arr[i];
        else
            cout << arr[i] << ", ";
    }
    cout << "]\n";
}

int main()
{
    array<int, 3> nums = {1, 2, 3};

    // [1, 2, 3]보다 작은 순열은 존재하지 않아 false(0)를 return한다.
    cout << "[1, 2, 3]의 사전 순 이전 순열 존재 여부: "
         << prev_permutation(nums.begin(), nums.end()) << '\n';

    print_arr(nums); // 순열은 사전 마지막 순열로 변했다.

    // [3, 2, 1]보다 작은 순열은 존재하지 않아 false(0)를 return한다.
    cout << "[3, 2, 1]의 사전 순 다음 순열 존재 여부: "
         << next_permutation(nums.begin(), nums.end()) << '\n';
    // next_permutation 함수 호출 이후, 순열은 사전 첫 순열로 변했다.

    do
    {
        print_arr(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    // next_permutation을 이용해
    // 사전 첫 순열부터 사전 마지막 순열까지 탐색한다.
    // == 모든 순열에 대해 탐색한다.
}