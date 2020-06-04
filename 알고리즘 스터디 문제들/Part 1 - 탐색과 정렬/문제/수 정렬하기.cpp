#include <iostream>
#include <vector>
using namespace std;

// 버블 정렬 구현
void bubble_sort(vector<int> &v)
{
    int tmp; // 교환하는 값을 임시로 저장하는 변수
    for (size_t i = 0; i < v.size(); i++)
    {
        for (size_t j = 0; j < v.size() - (i + 1); j++)
        {
            if (v[j] > v[j + 1])
            {
                tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
            }
        }
    }
}

// 선택 정렬 구현
void selection_sort(vector<int> &v)
{
    int tmp;      // 교환하는 값을 임시로 저장하는 변수
    int minIndex; // 최솟값의 index를 임시로 저장하는 변수
    for (size_t i = 0; i < v.size() - 1; i++)
    {
        minIndex = i;
        for (size_t j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[minIndex])
                minIndex = j;
        }

        tmp = v[i];
        v[i] = v[minIndex];
        v[minIndex] = tmp;
    }
}

// 삽입 정렬 구현
void insertion_sort(vector<int> &v)
{
    int tmp; // 교환하는 값을 임시로 저장하는 변수
    for (size_t i = 1; i < v.size(); i++)
    {
        tmp = v[i];
        for (int j = i - 1; j >= 0 && tmp < v[j]; j--)
        {
            v[j + 1] = v[j];
            v[j] = tmp;
        }
    }
}

int main()
{
    size_t N;
    cin >> N;

    vector<int> nums(N);
    for (size_t i = 0; i < N; i++)
        cin >> nums[i];

    // bubble_sort(nums);
    // selection_sort(nums);
    insertion_sort(nums);

    for (size_t i = 0; i < N; i++)
        cout << nums[i] << '\n';
}