#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    cout << (N == 1 && M == 1 ? 0 : (N * M) - 1) << '\n';
}

/*

1 1 1
1 1 1
1 1 1

1 1 1

1 1 1
1 1 1

1 1 1

1 1 1

1 1 1 -> 8

---

1 1 1
1 1 1
1 1 1

1 1 1
1 1 1

1 1 1

1  1  1
1  1  1

1 1 1


*/