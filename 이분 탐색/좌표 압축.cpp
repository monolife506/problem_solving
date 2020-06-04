// 18870번: 좌표 압축
// unique 함수 사용

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> ordered(N);
    vector<int> compressed(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> ordered[i];
        compressed[i] = ordered[i];
    }

    sort(ordered.begin(), ordered.end());
    ordered.erase(unique(ordered.begin(), ordered.end()), ordered.end());
    for (size_t i = 0; i < N; i++)
        cout << (int)(lower_bound(ordered.begin(), ordered.end(), compressed[i]) - ordered.begin()) << " ";
}