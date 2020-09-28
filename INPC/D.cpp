
#include <iostream>
using namespace std;

int H, Y;
int getMax(int curH, int curY, int Bcnt, int Ccnt) {
  if (curY == Y) return curH;
  int A = getMax((curH * 105) / 100, curY + 1, 0, 0);

  int B;
  if (Bcnt == 2)
    B = getMax((curH * 120) / 100, curY + 1, 0, 0);
  else
    B = getMax(curH, curY + 1, Bcnt + 1, 0);

  int C;
  if (Ccnt == 4)
    C = getMax((curH * 135) / 100, curY + 1, 0, 0);
  else
    C = getMax(curH, curY + 1, 0, Ccnt + 1);

  return max(A, max(B, C));
}

int main() {
  cin >> H >> Y;
  cout << getMax(H, 0, 0, 0);
}

// 1 3 5