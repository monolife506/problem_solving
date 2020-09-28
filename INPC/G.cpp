#include <iostream>
using namespace std;

int dist(int X1, int Y1, int Z1, int X2, int Y2, int Z2) {
  return (X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2) + (Z1 - Z2) * (Z1 - Z2);
}

int main() {
  int N, K[100];
  int X1, Y1, Z1;
  int X2, Y2, Z2;
  int curX = X1, curY = Y1, curZ = Z1;
  cin >> X1 >> Y1 >> Z1 >> X2 >> Y2 >> Z2;
  for (size_t i = 0; i < N; i++) cin >> K[i];

  for (size_t i = 0; i < N; i++) {
    int disttoFin = dist(curX, curY, curZ, X2, Y2, Z2);
    int curMin = abs(dist(curX, curY, curZ, X2, Y2, Z2) - K[i]);
    int curMax = abs(dist(curX, curY, curZ, X2, Y2, Z2) + K[i]);

    if (i == N - 1) cout << ((K[i] == disttoFin) ? "YES" : "NO");
  }
}

// 40 25 22 10 10 8 7 5 4 3
