#include <iostream>
using namespace std;

#define TREESIZE 262142

int H[100001];
int tree[TREESIZE];  // 세그먼트 트리

int N, M;
int a, b, k;

void init(int idx, int start, int end) {
  if (start == end) {
    tree[idx] = H[start];
    return;
  }

  int mid = (start + end) / 2;
  tree[idx] = 0;

  init(idx * 2, start, mid);
  init(idx * 2 + 1, mid + 1, end);
}

void update(int idx, int start, int end) {
  // 구간을 완전히 벗어난 경우
  if (end < a || start > b) return;

  // 구간 중간에 걸치는 경우
  if (a <= start && b >= end) {
    tree[idx] += k;

    return;
  }

  // 구간을 포함하고 있는 경우
  int mid = (start + end) / 2;
  update(idx * 2, start, mid);
  update(idx * 2 + 1, mid + 1, end);
}

int getnum(int idx, int start, int end, int target, int sum) {
  // 구간을 완전히 벗어난 경우
  if (end < target || start > target) return 0;

  // 구간에 일치하는 경우
  if (start == end && start == target) return sum + tree[idx];

  // 구간을 포함하고 있는 경우
  int mid = (start + end) / 2;
  if (target <= mid)
    return getnum(idx * 2, start, mid, target, sum + tree[idx]);
  else
    return getnum(idx * 2 + 1, mid + 1, end, target, sum + tree[idx]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  for (size_t i = 1; i <= N; i++) cin >> H[i];
  init(1, 1, N);

  for (size_t i = 0; i < M; i++) {
    cin >> a >> b >> k;
    update(1, 1, N);
  }

  for (size_t i = 1; i <= N; i++) {
    cout << getnum(1, 1, N, i, 0) << " ";
  }
}