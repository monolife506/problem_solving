#include <algorithm>
#include <iostream>
using namespace std;

int ans[10];
int choice[10];
int total;

void getscore(int cnt, int before, int before2) {
  if (cnt == 10) {
    int cnt = 0;
    for (size_t i = 0; i < 10; i++) {
      if (ans[i] == choice[i]) cnt++;
    }

    if (cnt >= 5) total++;
    return;
  }

  for (size_t i = 1; i <= 5; i++) {
    if (before == before2 && i == before) continue;

    choice[cnt] = i;
    getscore(cnt + 1, i, before);
  }
}

int main() {
  for (size_t i = 0; i < 10; i++) cin >> ans[i];
  getscore(0, -1, -1);
  cout << total;
}