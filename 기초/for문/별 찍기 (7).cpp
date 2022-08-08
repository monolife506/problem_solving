#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = 0; j < N - (i + 1); ++j)
            cout << ' ';
        for (int j = 0; j < (i + 1) * 2 - 1; ++j)
            cout << '*';

        cout << '\n';
    }

    for (int i = 0; i < N * 2 - 1; ++i)
        cout << '*';

    cout << '\n';

    for (int i = N - 2; i >= 0; --i)
    {
        for (int j = 0; j < N - (i + 1); ++j)
            cout << ' ';
        for (int j = 0; j < (i + 1) * 2 - 1; ++j)
            cout << '*';

        cout << '\n';
    }
}