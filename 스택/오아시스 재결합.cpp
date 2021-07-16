#include <iostream>
#include <stack>
using namespace std;
typedef pair<int, int> P;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, num;
    long long ans = 0;
    stack<P> S;

    cin >> N >> num;
    S.push(P(num, 1));
    for (size_t i = 1; i < N; i++) {
        cin >> num;

        if (num < S.top().first) {
            ans++;
            S.push(P(num, 1));
        } else if (num == S.top().first) {
            int cnt = S.top().second;
            ans += (cnt != S.size()) ? cnt + 1 : cnt;
            S.push(P(num, cnt + 1));
        } else {
            while (!S.empty() && num > S.top().first) {
                ans++;
                S.pop();
            }
            if (!S.empty()) {
                ans++;
                if (num == S.top().first) {
                    int cnt = S.top().second;
                    ans += (cnt != S.size()) ? cnt : cnt - 1;
                    S.push(P(num, cnt + 1));
                    continue;
                }
            }
            S.push(P(num, 1));
        }
    }

    cout << ans << '\n';
}

// 1 2 2 1
// 1 + 1 + 1 == 3

// 6 6 1 2 3 6
// 1 + 1 + 2 + 2 + 3 == 9

// 3 3 2 2 1 1
// 1 + 1 + 2 + 1 + 2 == 7

// 5 4 3 4 5
// 1 + 1 + 3 + 3 == 8

// 4 3 2 1 2 3
// 1 + 1 + 1 + 3 + 4 == 10

// 4 3 3 2 1 4
// 1 + 2 + 1 + 1 + 5 == 10