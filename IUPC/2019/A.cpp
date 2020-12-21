#include <iostream>
using namespace std;

int main()
{
    int N, num, ans = 0;
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> num;
        ans = max(ans, num);
    }
    cout << ans;
}