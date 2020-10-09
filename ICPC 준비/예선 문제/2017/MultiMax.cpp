#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, input;
    cin >> n;

    vector<int> v1, v2;
    for (size_t i = 0; i < n; i++)
    {
        cin >> input;
        (input >= 0) ? v1.push_back(input) : v2.push_back(input);
    }

    sort(v1.begin(), v1.end(), greater<int>());
    sort(v2.begin(), v2.end());

    int num1 = 0, num2 = 0;
    if (v1.size() > 1)
        num1 = v1[0] * v1[1];
    if (v2.size() > 1)
        num2 = v2[0] * v2[1];

    if (v1.size() > 2)
        num1 = max(num1, num1 * v1[2]);
    if (v1.size() > 0)
        num2 = max(num2, num2 * v1[0]);

    cout << max(num1, num2);
}

// 양수 양수 양수
// 음수 음수 양수
// 양수 양수
// 음수 음수
