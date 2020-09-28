#include <cstring>
#include <iostream>
using namespace std;

int H, W, O, F;
int startR, startC;
int endR, endC;
int map[101][101];
int dp[101][101];  // 그 칸에서의 최대 힘

void dfs(int R, int C, int curF) {
  static int dr[4] = {0, 0, 1, -1};
  static int dc[4] = {1, -1, 0, 0};

  if (R == endR && C == endC) return;
  if (curF == 0) return;

  for (size_t i = 0; i < 4; i++) {
    int nextR = R + dr[i];
    int nextC = C + dc[i];
    if (nextR > H || nextR <= 0 || nextC > W || nextC <= 0) continue;
    if (curF >= map[nextR][nextC] - map[R][C] && curF - 1 > dp[nextR][nextC]) {
      dp[nextR][nextC] = curF - 1;
      dfs(nextR, nextC, curF - 1);
    }
  }
}

int main() {
  size_t T;
  cin >> T;
  for (size_t tc = 0; tc < T; tc++) {
    memset(map, 0, sizeof(map));
    memset(dp, -1, sizeof(dp));
    cin >> H >> W >> O >> F >> startR >> startC >> endR >> endC;
    for (size_t i = 0; i < O; i++) {
      int R, C, L;
      cin >> R >> C >> L;
      map[R][C] = L;
    }

    dp[startR][startC] = F;
    dfs(startR, startC, F);
    cout << (dp[endR][endC] >= 0 ? "잘했어!!\n" : "인성 문제있어??\n");
  }
}