#include <iostream>
#include <string>
using namespace std;

int sum[10010];

int main()
{
    string a, b;
    cin >> a >> b;

    int n = max(a.length(), b.length()), tmp = 0;

    for (int i = 0; i <= n; ++i)
    {
        int a_idx = a.length() - (i + 1);
        int b_idx = b.length() - (i + 1);
        int a_num = (a_idx >= 0) ? a[a_idx] - '0' : 0;
        int b_num = (b_idx >= 0) ? b[b_idx] - '0' : 0;

        sum[i] = (a_num + b_num + tmp) % 10;
        tmp = (a_num + b_num + tmp) / 10;
    }

    if (sum[n] != 0)
        cout << sum[n];
    for (int i = n - 1; i >= 0; i--)
        cout << sum[i];

    cout << '\n';
}