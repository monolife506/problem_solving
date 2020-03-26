#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    size_t T;
    cin >> T;

    for (size_t i = 0; i < T; i++)
    {
        int A, B;
        cin >> A >> B;
        cout << A + B << '\n';
    }
}
