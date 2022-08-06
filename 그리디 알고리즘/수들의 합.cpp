#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll S;
    cin >> S;

    int num = 1;
    while (true)
    {
        ll sum = 1LL * num * (num - 1) / 2;
        if (S - sum < num)
            break;
        else if (S - sum == num)
        {
            ++num;
            break;
        }

        ++num;
    }

    cout << num - 1 << '\n';
}