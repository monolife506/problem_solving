#include <cstring>
#include <iostream>
#include <map>
using namespace std;

struct Nation {
  int X;
  int Y;
  int K;  // 병사 수

  Nation(int x, int y, int k) : X(x), Y(y), K(k) {}
};

int N, M, Q;
int num[2001][2001];  // 땅을 차지한 국가의 번호
map<int, Nation> nations;

void battle(int t, int X1, int Y1, int X2, int Y2) {
  if (nations[num[X1][Y1]].K > nations[num[X2][Y2]].K) {
  } else if (nations[num[X1][Y1]].K < nations[num[X2][Y2]].K) {
  }
}

int getcnt(int t, int X, int Y) { return nations[num[X][Y]].K + t; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M >> Q;
  for (size_t i = 0; i < M; i++) {
    int X, Y, K;
    cin >> X >> Y >> K;
    root[X][Y] = 0;
    nations[X * N + Y] = Nation(X, Y, K);
  }
}
