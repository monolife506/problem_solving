#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ans = 0;
    for (int i = 0; i < 5; ++i)
    {
        int A;
        cin >> A;
        ans += A;
    }
    cout << ans << '\n';
}