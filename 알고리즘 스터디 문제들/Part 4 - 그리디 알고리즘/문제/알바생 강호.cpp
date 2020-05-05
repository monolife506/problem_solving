#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    size_t N;
    cin >> N;
    vector<int> T(N);
    for (size_t i = 0; i < N; i++)
        cin >> T[i];
    sort(T.begin(), T.end(), greater<int>());

    int tip;
    long long total = 0;
    for (size_t i = 0; i < N; i++)
    {
        tip = T[i] - i;
        if (tip > 0)
            total += tip;
        else
            break; // 그 다음 팁들은 모두 0임
    }
    cout << total;
}