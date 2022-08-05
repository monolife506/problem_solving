#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll cache[5000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cache[0] = cache[2] = 1;
    for (int i = 4; i <= 5000; i += 2)
    {
        for (int j = 0; j <= i - 2; j += 2)
        {
            cache[i] += cache[j] * cache[i - 2 - j];
            cache[i] %= MOD;
        }
    }

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        int L;
        cin >> L;
        cout << cache[L] << '\n';
    }
}

/*

()

()()
(())

(0)4
()()()
()(())

(2)
(())()

(4)
(()())
((()))

*/