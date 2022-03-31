#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

P cycle[4];

int main() {
  ll V0, V, M, T;
  cin >> V0 >> M >> T;

  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, -1, 0, 1};
  P cur = P(0, 0);

  // First Cycle
  cur.first += V0;
  V = (V0 * M) % 10;

  // Second Cycle
  if (T-- > 1) {
    cycle[0].first = V * dy[0];
    cycle[0].second = V * dx[0];
    V = (V * M) % 10;
    for (size_t i = 1; i < 4; i++) {
      cycle[i].first = cycle[i - 1].first + V * dy[i];
      cycle[i].second = cycle[i - 1].second + V * dx[i];
      V = (V * M) % 10;
    }

    cur.first += cycle[3].first * (T / 4);
    cur.second += cycle[3].second * (T / 4);
    if (T % 4 != 0) {
      cur.first += cycle[(T - 1) % 4].first;
      cur.second += cycle[(T - 1) % 4].second;
    }
  }

  cout << cur.second << " " << cur.first;
}

// 12 14
// 0 12 (12)
// 8 12 (8)
// 8 10 (2)
// 0 10 (8)
// 0 12 (2)
// 8 12 (8)
// 8 10 (2)
// 0 10 (8)
// 0 12 (12)