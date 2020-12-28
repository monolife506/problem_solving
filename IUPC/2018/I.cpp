#include <iostream>
using namespace std;
typedef long long ll;

int N, zeroX, zeroY;
ll arr[500][500];
ll correctSum;
ll rowSum[500];
ll colSum[500];
ll crossSum[2];

bool check(ll M)
{
    for (size_t i = 0; i < N; i++) {
        ll curRow = rowSum[i];
        ll curCol = colSum[i];

        if (i == zeroX)
            curRow += M;
        if (i == zeroY)
            curCol += M;

        if (correctSum != curRow || correctSum != curCol)
            return false;
    }

    ll curCross[2];
    curCross[0] = crossSum[0];
    curCross[1] = crossSum[1];

    if (zeroX == zeroY)
        curCross[0] += M;
    if (zeroX + zeroY == N - 1)
        curCross[1] += M;
    return (correctSum == curCross[0] && correctSum == curCross[1]);
}

int main()
{

    cin >> N;

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                zeroX = i;
                zeroY = j;
            }
        }
    }

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            rowSum[i] += arr[i][j];
            colSum[i] += arr[j][i];
        }

        crossSum[0] += arr[i][i];
        crossSum[1] += arr[N - (i + 1)][i];
    }
    correctSum = rowSum[!zeroX];

    if (!check(0) && check(correctSum - rowSum[zeroX]))
        cout << correctSum - rowSum[zeroX] << '\n';
    else
        cout << -1 << '\n';
}