#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    int ans = 0;
    for (int q = 0; q < Q; ++q)
    {
        int a, l, r;
        cin >> a >> l >> r;
        if (a == 1)
            ans = !ans;
        else if (((r - l + 1) / 2) % 2 == 1)
            ans = !ans;

        cout << ans << '\n';
    }
}

/*

1 2
2 1 -> +1

1 2 3 4
4 2 3 1 -> +5

1 2 3 4 5
5 2 3 4 1 -> 4 + 3 = 7

1 2 3 4
1 4 3 2 -> +3

a == 1
l a b c d .. r
중간에 있는 수가 k개면
+ or - (2k + 1)

a == 2 -> (r - l + 1) / 2회 a번 수행

1 2 3 4 5 6 7 8
1 2 3 4 5 6

*/