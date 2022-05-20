#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    ll sum = 0;
    int max_d = 0;
    for (int i = 0; i < N; ++i)
    {
        int d;
        cin >> d;

        sum += d;
        max_d = max(max_d, d);
    }

    if (N == 1)
        cout << (max_d == 1 ? "Happy" : "Unhappy") << '\n';
    else
        cout << (sum - max_d >= max_d ? "Happy" : "Unhappy") << '\n';
}