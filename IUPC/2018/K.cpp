#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
vector<int> cut;

bool check(int length)
{
    for (size_t start = 0; start < M; start++) {
        int lineCnt = 0;
        int curLen = 0;
        for (size_t i = 0; i < M; i++) {
            int cur = (start + i) % M;
            int next = (start + (i + 1)) % M;
            int len = abs(cut[next] - cut[cur]);

            if (next == 0)
                len = N - len;

            curLen += len;
            if (curLen >= length) {
                curLen = 0;
                lineCnt++;
            }
        }

        if (lineCnt >= K)
            return true;
    }

    return false;
}

int binary_search()
{
    int left = 1;
    int right = N;
    int middle, ans;

    while (left <= right) {
        middle = (left + right) / 2;
        if (check(middle)) {
            ans = middle;
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for (size_t i = 0; i < M; i++) {
        int X;
        cin >> X;
        cut.push_back(X);
    }

    cout << binary_search();
}