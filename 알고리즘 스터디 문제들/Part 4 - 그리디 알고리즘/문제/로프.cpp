#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> W(N);
    for (size_t i = 0; i < N; i++)
        cin >> W[i];
    sort(W.begin(), W.end(), greater<int>());

    int ans = 0;
    for (size_t i = 0; i < N; i++)
    {
        if (ans < W[i] * (i + 1))
            ans = W[i] * (i + 1);
    }
    cout << ans;
}
