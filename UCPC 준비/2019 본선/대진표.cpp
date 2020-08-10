#include <iostream>
using namespace std;

int print(int cur)
{
    size_t curSlot = 0;
    size_t maxSlot = 1;
    while (maxSlot < cur)
        maxSlot *= 2;

    if (cur == 1)
    {
        cout << "#";
        return 1;
    }
    if (cur == 2)
    {
        cout << "##";
        return 2;
    }

    if (cur <= (3 * maxSlot) / 4)
        curSlot = print(cur - (maxSlot / 4)) + print(maxSlot / 4);
    else
        curSlot = print(maxSlot / 2) + print(cur - (maxSlot / 2));

    for (size_t i = curSlot; i < maxSlot; i++)
    {
        cout << '.';
        curSlot++;
    }

    return curSlot;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    if (N != 1)
        print(N);
    else
        cout << "#";
}

// #. (1)
// ## (2)
// ###. (2 + 1)
// #### (2 + 2)
// ###.##.. (3 + 2)
// ###.###. (3 + 3)
// #######. (4 + 3)
// ######## (4 + 4)
// ###.##..####.... (5 + 4)
// ###.##..###.##.. (5 + 5)
// ###.###.###.##.. (6 + 5)
// ###.###.###.###. (6 + 6)