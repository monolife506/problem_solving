#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int min_val = 0, max_val = 0;
    for (int i = 0; i < n + 1; ++i)
    {
        min_val += 2;
        max_val += 3;
    }

    cout << min_val << " " << max_val << '\n';
}