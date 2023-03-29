#include <iostream>
using namespace std;

int sum[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    for (size_t i = 1; i <= N; i++) {
        int num;
        cin >> num;
        sum[i] = sum[i - 1] + num;
    }

    for (size_t t = 0; t < M; t++) {
        int i, j;
        cin >> i >> j;
        cout << sum[j] - sum[i - 1] << '\n';
    }
}