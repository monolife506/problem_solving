#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n[6];
    int ans[6] = {1, 1, 2, 2, 2, 8};
    for (int i = 0; i < 6; ++i)
        cin >> n[i];
    for (int i = 0; i < 6; ++i)
        cout << ans[i] - n[i] << " ";

    cout << '\n';
}