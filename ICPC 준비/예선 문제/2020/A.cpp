#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    size_t N;
    cin >> N;

    vector<int> LIS;
    for (size_t i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if (LIS.empty() || num >= LIS.back())
            LIS.push_back(num);
        else
            *upper_bound(LIS.begin(), LIS.end(), num) = num;
    }

    cout << N - LIS.size();
}