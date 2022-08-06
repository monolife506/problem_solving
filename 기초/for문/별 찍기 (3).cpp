#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for (int i = N; i > 0; --i)
    {
        for (int j = 0; j < i; ++j)
            cout << '*';
        cout << '\n';
    }
}