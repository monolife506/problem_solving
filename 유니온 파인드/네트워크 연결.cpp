#include <cstring>
#include <iostream>
using namespace std;

int N, root[20001], length[20001];

int find(int i)
{
    if (root[i] == -1)
        return i;

    int j = find(root[i]);
    length[i] += length[root[i]];
    return root[i] = j;
}

void merge(int i, int j)
{
    length[i] = abs(i - j) % 1000;
    root[i] = j;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t T;
    cin >> T;
    for (size_t tc = 0; tc < T; tc++)
    {
        memset(root, -1, sizeof(root));
        memset(length, 0, sizeof(length));
        cin >> N;

        char cmd;
        cin >> cmd;
        while (cmd != 'O')
        {
            if (cmd == 'E')
            {
                int i;
                cin >> i;
                find(i);
                cout << length[i] << '\n';
            }
            else
            {
                int i, j;
                cin >> i >> j;
                merge(i, j);
            }

            cin >> cmd;
        }
    }
}