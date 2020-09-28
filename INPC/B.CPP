#include <iostream>
using namespace std;

int main() {
  int N, ans = 0;
  cin >> N;
  if (N < 0)
    ans = 32;
  else if (N > 0) {
    while (N > 0) {
      N /= 2;
      ans++;
    }
  } else
    ans = 1;

  cout << ans;
}