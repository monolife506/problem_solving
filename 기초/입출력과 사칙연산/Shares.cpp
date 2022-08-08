#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, S;
    while (cin >> N >> S)
    {
        cout << S / (N + 1) << '\n';
    }
}