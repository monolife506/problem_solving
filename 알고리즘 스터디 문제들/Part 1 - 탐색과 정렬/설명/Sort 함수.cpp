#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void vector_display(const vector<int> &v)
{
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    cout << '\n';
}

bool cmp(const int &A, const int &B)
{
    return A > B;
}

int main()
{
    vector<int> arr1 = {1, 29, 32, 45, 23, 52, 47};
    vector_display(arr1);

    // 오름차순 정렬
    sort(arr1.begin(), arr1.end());
    vector_display(arr1);

    // 내림차순 정렬
    sort(arr1.begin(), arr1.end(), cmp);
    vector_display(arr1);
}