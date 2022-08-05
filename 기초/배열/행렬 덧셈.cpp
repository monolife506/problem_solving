#include <iostream>
using namespace std;

int A[100][100], B[100][100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            cin >> A[i][j];
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            cin >> B[i][j];
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            cout << A[i][j] + B[i][j] << " ";
        cout << '\n';
    }
}