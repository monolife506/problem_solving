#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc)
    {
        int N;
        cin >> N;

        if (N % 2 == 1)
            cout << 1LL * N * (N - 1) * (N - 2) << '\n';
        else
        {
            if (N % 3 == 0)
                cout << 1LL * (N - 1) * (N - 2) * (N - 3) << '\n';
            else
                cout << 1LL * N * (N - 1) * (N - 3) << '\n';
        }
    }
}