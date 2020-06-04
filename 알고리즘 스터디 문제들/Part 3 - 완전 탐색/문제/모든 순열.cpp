#include <iostream>
#include <vector>
using namespace std;

bool next_permuatation(vector<int> &arr)
{
    // 크기가 2 이상인 수열에 대해서만 실시함.

    int i;
    for (i = arr.size() - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
            break;
    }

    // 사전 다음 순열이 없는 경우
    if (i == -1)
        return false;

    int j;
    for (j = arr.size() - 1; j > i; j--)
    {
        if (arr[j] > arr[i])
            break;
    }

    swap(arr[i], arr[j]); // C++ 기본 함수 - 두 변수의 위치를 바꿈

    // 스왑할 영역의 항목의 개수
    int swap_size = arr.size() - (i + 1);
    for (size_t k = 0; k < swap_size / 2; k++)
        swap(arr[k + (i + 1)], arr[arr.size() - (k + 1)]);
    return true;
}

int main()
{
    size_t N;
    cin >> N;

    vector<int> arr(N);
    for (size_t i = 0; i < N; i++)
        arr[i] = i + 1;

    do
    {
        for (size_t i = 0; i < N; i++)
            cout << arr[i] << " ";
        cout << '\n';
    } while (next_permuatation(arr));
}