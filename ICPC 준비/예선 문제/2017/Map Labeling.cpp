#include <iostream>
using namespace std;

int n;
int p[10001];
int w[10001];

int dp[10001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (size_t i = 0; i < n; i++)
        cin >> p[i];
    for (size_t i = 0; i < n; i++)
        cin >> w[i];
}

// a
// 1
