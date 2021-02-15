#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct P {
  ll x = 0;
  ll y = 0;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  size_t T;
  cin >> T;
  for (size_t tc = 0; tc < T; tc++) {
    size_t N;
    cin >> N;

    vector<P> p(N);
    for (size_t i = 0; i < N; i++) cin >> p[i].x >> p[i].y;

    vector<bool> choice(N / 2, false);
    for (size_t i = 0; i < N / 2; i++) choice.push_back(true);

    double ans = 1'000'000'000'000;
    do {
      ll x = 0;
      ll y = 0;

      for (size_t i = 0; i < N; i++) {
        if (choice[i]) {
          x += p[i].x;
          y += p[i].y;
        } else {
          x -= p[i].x;
          y -= p[i].y;
        }
      }

      double tmp = sqrt(x * x + y * y);
      ans = min(ans, tmp);
    } while (next_permutation(choice.begin(), choice.end()));

    cout << fixed << setprecision(12) << ans << '\n';
  }
}