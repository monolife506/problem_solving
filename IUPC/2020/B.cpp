#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> arr;

    int N, M;
    cin >> N >> M;
    for (size_t i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    for (size_t i = 0; i < M; i++) {
        int D;
        cin >> D;

        auto idx = lower_bound(arr.begin(), arr.end(), D);
        if (idx == arr.end() || *idx != D)
            cout << -1 << '\n';
        else
            cout << (int)(idx - arr.begin()) << '\n';
    }
}