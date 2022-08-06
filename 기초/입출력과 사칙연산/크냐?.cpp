#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int A, B;
    cin >> A >> B;
    while (A != 0 || B != 0)
    {
        cout << (A > B ? "Yes" : "No") << '\n';
        cin >> A >> B;
    }
}