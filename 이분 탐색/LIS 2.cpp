// 12015번: 가장 긴 증가하는 부분 수열 2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    size_t N;
    cin >> N;

    vector<int> LIS(1, INT32_MIN);
    for (size_t i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if (num > *(LIS.end() - 1))
        {
            if (*(LIS.end() - 1) == INT32_MIN)
                *(LIS.end() - 1) = num;
            else
                LIS.push_back(num);
        }
        else
            *lower_bound(LIS.begin(), LIS.end(), num) = num;
    }

    cout << LIS.size() << '\n';
    for (const int &item : LIS)
        cout << item << " ";
}
