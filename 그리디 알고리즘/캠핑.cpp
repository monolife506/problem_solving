#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc = 1;
    while (true)
    {
        ll L, P, V;
        cin >> L >> P >> V;

        if (L == 0 && P == 0 && V == 0)
            break;

        cout << "Case " << tc++ << ": "
             << (V / P) * L + min(L, V % P) << '\n';
    }
}

/*

10
20
28

10 / 20

5
8
20

5 / 8 (5) / 7 (5)

*/