#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int X, N;
    cin >> X >> N;

    int total = 0;
    for (int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;

        total += a * b;
    }

    cout << (total == X ? "Yes" : "No") << '\n';
}