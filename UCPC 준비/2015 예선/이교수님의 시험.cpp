#include <iostream>
using namespace std;

bool flag[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, num;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cin >> num;
            if (num != (((j - 1) % 5) + 1))
                flag[i] = true;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (!flag[i])
            cout << i << '\n';
    }
}