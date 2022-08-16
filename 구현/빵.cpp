#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int ans = INT32_MAX;
    for (int i = 0; i < N; ++i)
    {
        int A, B;
        cin >> A >> B;
        if (A <= B)
            ans = min(ans, B);
    }

    cout << (ans != INT32_MAX ? ans : -1) << '\n';
}