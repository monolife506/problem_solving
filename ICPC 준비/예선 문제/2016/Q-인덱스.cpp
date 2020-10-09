#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];

int main()
{
    int n, q = 0;
    cin >> n;
    for (size_t i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= n - i)
            q = max(q, n - i);
    }
    cout << q;
}