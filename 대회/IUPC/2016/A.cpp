#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char problem, C;
    int T, M, N;
    cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        cin >> M >> problem;
        for (size_t j = 0; j < M; j++)
        {
            if (problem == 'C')
            {
                cin >> C;
                cout << (int)(C - 'A' + 1) << " ";
            }
            else
            {
                cin >> N;
                cout << (char)(N + 'A' - 1) << " ";
            }
        }
        cout << '\n';
    }
}