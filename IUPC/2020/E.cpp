#include <iostream>
using namespace std;
typedef long long ll;

int N, M;
ll arr[2000][2000];
ll H[2000][2000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            cin >> arr[i][j];
            arr[i][j] *= -1;
        }
    }

    for (int i = 0; i + (M / 2) < N; i++) {
        for (int j = 0; j + (M / 2) < N; j++) {
            int curX = i + (M / 2);
            int curY = j + (M / 2);
            H[curX][curY] = arr[i][j];

            if (i > 0)
                H[curX][curY] -= arr[i - 1][j];
            if (j > 0)
                H[curX][curY] -= arr[i][j - 1];
            if (i > 0 && j > 0)
                H[curX][curY] += arr[i - 1][j - 1];

            if (curX - M >= 0)
                H[curX][curY] += H[curX - M][curY];
            if (curY - M >= 0)
                H[curX][curY] += H[curX][curY - M];
            if (curX - M >= 0 && curY - M >= 0)
                H[curX][curY] -= H[curX - M][curY - M];
        }
    }

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++)
            cout << H[i][j] << " ";
        cout << '\n';
    }
}

// 8 9 9 1 11 9 1 8
// 6 13 11
// 6 8 0