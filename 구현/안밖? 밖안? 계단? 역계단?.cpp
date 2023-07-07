#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string S;
    cin >> S;

    if (S == "fdsajkl;" || S == "jkl;fdsa")
        cout << "in-out" << '\n';
    else if (S == "asdf;lkj" || S == ";lkjasdf")
        cout << "out-in" << '\n';
    else if (S == "asdfjkl;")
        cout << "stairs" << '\n';
    else if (S == ";lkjfdsa")
        cout << "reverse" << '\n';
    else
        cout << "molu" << '\n';
}