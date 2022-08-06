#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int t = (A * 60 * 60 + B * 60 + C + D) % (60 * 60 * 24);
    cout << t / (60 * 60) << ' ';
    cout << (t % (60 * 60)) / 60 << ' ';
    cout << t % 60 << '\n';
}