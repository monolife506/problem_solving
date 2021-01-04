#include <iostream>
#include <queue>
using namespace std;
typedef pair<double, double> P;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, ans = 0;
    priority_queue<P> lines;
    priority_queue<double> lasers;

    cin >> N;
    for (size_t i = 0; i < N; i++) {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if ((y1 / x1) >= (y2 / x2))
            lines.push(P((y1 / x1), (y2 / x2)));
        else
            lines.push(P((y2 / x2), (y1 / x1)));
    }

    cin >> M;
    for (size_t i = 0; i < M; i++) {
        double x, y;
        cin >> x >> y;
        lasers.push((y / x));
    }

    while (!lasers.empty()) {
        double curLaser = lasers.top();
        lasers.pop();

        while (!lines.empty()) {
            P curLine = lines.top();
            if (curLine.first >= curLaser && curLine.second <= curLaser) {
                lines.pop();
                ans++;
            } else if (curLine.second > curLaser) {
                lines.pop();
            } else {
                break;
            }
        }
    }

    cout << N - ans;
}