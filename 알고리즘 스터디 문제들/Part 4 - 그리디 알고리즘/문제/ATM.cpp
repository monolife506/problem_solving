#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    size_t N;
    cin >> N;
    vector<int> P(N);
    for (size_t i = 0; i < N; i++)
        cin >> P[i];
    sort(P.begin(), P.end());

    int total = 0;
    for (size_t i = 0; i < N; i++)
        total += P[i] * (N - i);
    cout << total;
}