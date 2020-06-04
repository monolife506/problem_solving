#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string input;
    cin >> input;

    vector<char> nums(input.length()); // 각 자릿수를 담는 배열
    for (size_t i = 0; i < input.length(); i++)
        nums[i] = input[i];

    // 기본 함수로 내림차순 정렬
    sort(nums.begin(), nums.end(), greater<char>());
    for (size_t i = 0; i < input.length(); i++)
        cout << nums[i];
}