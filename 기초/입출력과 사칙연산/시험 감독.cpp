#include <iostream>
using namespace std;
typedef long long ll;

int A[1000000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    int B, C;
    cin >> B >> C;

    ll ans = 0;
    for (int i = 0; i < N; ++i)
    {
        if (A[i] <= B)
            ans += 1;
        else
            ans += 1 + ((A[i] - B) + C - 1) / C;
    }

    cout << ans << '\n';
}