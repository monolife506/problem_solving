#include <algorithm>
#include <iostream>
using namespace std;

int x[1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, k;
    cin >> N >> k;
    for (int i = 0; i < N; ++i)
        cin >> x[i];

    sort(x, x + N, greater<int>());
    cout << x[k - 1] << '\n';
}