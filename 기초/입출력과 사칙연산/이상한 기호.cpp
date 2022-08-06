#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll A, B;
    cin >> A >> B;
    cout << (A + B) * (A - B) << '\n';
}