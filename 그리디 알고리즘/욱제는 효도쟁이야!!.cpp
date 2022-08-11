#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int sum = 0, max_val = 0;
    for (int i = 0; i < n; ++i)
    {
        int cost;
        cin >> cost;

        sum += cost;
        max_val = max(max_val, cost);
    }

    cout << sum - max_val << '\n';
}