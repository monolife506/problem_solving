#include <iostream>
using namespace std;

int H[30000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> H[i];

    int max_h = H[0], cnt = 0, ans = 0;
    for (int i = 1; i < N; ++i)
    {
        if (H[i] < max_h)
        {
            ++cnt;
            ans = max(ans, cnt);
        }
        else if (H[i] > max_h)
        {
            ans = max(ans, cnt);
            cnt = 0;
            max_h = H[i];
        }
    }

    cout << ans << '\n';
}