#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = N / 2; i >= 1; --i)
        cout << i << " " << i + (N / 2) << " ";
    if (N % 2 == 1)
        cout << N;

    cout << '\n';
}

// 10
// 5 10 4 9 3 8 2 7 1 6