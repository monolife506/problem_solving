#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (size_t i = 0; i < N; i++)
        cin >> A[i];

    int total = 0;
    reverse(A.begin(), A.end());
    for (size_t i = 0; i < N; i++)
    {
        total += K / A[i];
        K = K % A[i];
    }
    cout << total;
}