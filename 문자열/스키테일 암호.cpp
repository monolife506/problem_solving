#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int K;
    cin >> K;

    string S;
    cin >> S;
    for (int i = 0; i < S.length(); i += K)
        cout << S[i];

    cout << '\n';
}